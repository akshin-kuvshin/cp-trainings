// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;

const int LOG = 30;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n,
        q;
    cin >> n >> q;
    vector<int> t(n);
    for (auto& t_i : t) {
        cin >> t_i;
        --t_i;
    }

    vector<vector<int>> dp(n, vector<int>(LOG));
    for (int v = 0; v < n; ++v)
        dp[v][0] = t[v];
    for (int i = 1; i < LOG; ++i)
        for (int v = 0; v < n; ++v)
            dp[v][i] = dp[dp[v][i - 1]][i - 1];

    while (q--) {
        int v,
            k;
        cin >> v >> k;
        --v;

        for (int i = LOG - 1; i >= 0; --i)
            if ((1 << i) <= k) {
                v = dp[v][i];
                k -= (1 << i);
            }
        ++v;

        cout << v << '\n';
    }
}
