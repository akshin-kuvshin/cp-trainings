// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

void solve();
void heapify(vector<lli>& a, lli n);
void sort_heap_(vector<lli>& a, lli n);
void down(vector<lli>& a, lli n, lli x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;

    heapify(a, n);
    sort_heap_(a, n);

    for (auto a_i : a)
        cout << a_i << ' ';
    cout << '\n';
}

void heapify(vector<lli>& a, lli n) {
    for (int i = (int)n - 1; i >= 0; --i)
        down(a, n, i);
}

void sort_heap_(vector<lli>& a, lli n) {
    for (int i = (int)n - 1; i > 0; --i) {
        swap(a.front(), a[i]);
        down(a, (lli)i, 0LL);
    }
}

void down(vector<lli>& a, lli n, lli x) {
    bool was_swap;
    do {
        was_swap = false;

        lli x1 = (x << 1) + 1LL,
            x2 = (x << 1) + 2LL;
        if (x2 < n and a[x2] > a[x1])
            swap(x1, x2);
        if (x1 < n and a[x1] > a[x]) {
            swap(a[x], a[x1]);
            x = x1;
            was_swap = true;
        }
    } while (was_swap);
}
