// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

const lli MOD = (lli)1e9 + 7LL;

void solve();
lli C(lli n, lli k, lli mod);
lli inv(lli a, lli mod);
lli bin_pow(lli base, lli ptr, lli mod);

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

lli C(lli n, lli k, lli mod) {
    if (n - k < k)
        k = n - k;

    // C(n2, i2) = n2! / i2! / (n2 - i2)! = (n2 - i2 + 1) * ... * n2 / i2!
    lli C = 1LL;
    for (lli j = n - k + 1LL; j <= n; ++j)
         C = (C * j) % mod;
    lli k_fact = 1LL;
    for (lli j = 2LL; j <= k; ++j)
        k_fact = (k_fact * j) % mod;
    lli k_fact_inv = inv(k_fact, mod);
    C = (C * k_fact_inv) % mod;

    return C;
}

lli inv(lli a, lli mod) {
    // a ^ (p - 1) === 1
    // a ^ (p - 2) === a ^ (-1)
    return bin_pow(a, mod - 2LL, mod);
}

lli bin_pow(lli base, lli ptr, lli mod) {
    if (ptr == 0LL)
        return 1LL;
    if (ptr % 2LL == 1LL)
        return (base * bin_pow(base, ptr - 1LL, mod)) % mod;
    lli half = bin_pow(base, ptr / 2LL, mod);
    return (half * half) % mod;
}
