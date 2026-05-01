// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

const lli MOD = (lli)1e9 + 7LL;

void solve();

// НУЖНО РЕАЛИЗОВАТЬ ФУНКЦИЮ lli C(lli n, lli k, lli mod);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    lli n2 = 2LL * n;

    vector<vector<lli>> dp(n2 + 1LL, vector<lli>(n + 1LL));
    dp[0][0] = dp[1][1] = 1LL;
    for (int i = 2; i <= (int)n2; ++i)
        for (int j = 0; j <= (int)n; ++j) {
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if (j + 1 <= (int)n)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }

    lli ans = 0LL;
    for (lli i = 0LL; i <= n; ++i) {
        lli i2 = 2LL * i;
        lli j = C(n2, i2, MOD);
        ans = (ans + (((j * dp[i2][0]) % MOD) * dp[n2 - i2][0]) % MOD) % MOD;
    }

    cout << ans << '\n';
}
