// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve();
int the_only_one_prime_divisor(int x);
bool is_sorted(const vector<int>& a, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--)
        solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    if (is_sorted(a, n)) {
        cout << "Bob\n";
        return;
    }

    for (auto& ai : a) {
        int d = the_only_one_prime_divisor(ai);
        if (d == -1) {
            cout << "Alice\n";
            return;
        }
        ai = d;
    }
    cout << (is_sorted(a, n) ? "Bob" : "Alice") << '\n';
}

int the_only_one_prime_divisor(int x) {
    if (x == 1)
        return 1;

    unordered_set<int> prime_divisors;
    for (int d = 2; d * d <= x; ++d)
        while (x % d == 0) {
            prime_divisors.insert(d);
            x /= d;
        }
    if (x > 1)
        prime_divisors.insert(x);
    return prime_divisors.size() == 1 ? *prime_divisors.begin() : -1;
}

bool is_sorted(const vector<int>& a, int n) {
    for (int i = 0; i + 1 < n; ++i)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
