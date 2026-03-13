// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int lli;
using namespace std;

void solve();

const lli INF = (lli)1e18 + 1LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& ai : a)
        cin >> ai;
    auto b = a;
    sort(b.begin(), b.end());

    lli ans = INF;
    for (int i = 0; i < (int)n; ++i) {
        if (a[i] == b[i])
            continue;
        ans = min(ans, max(a[i] - b.front(), b.back() - a[i]));
    }

    cout << ((ans == INF) ? -1LL : ans) << '\n';
}
