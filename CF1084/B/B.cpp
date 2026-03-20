// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;

void solve();
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

    cout << (is_sorted(a, n) ? n : 1) << '\n';
}

bool is_sorted(const vector<int>& a, int n) {
    for (int i = 0; i + 1 < n; ++i)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
