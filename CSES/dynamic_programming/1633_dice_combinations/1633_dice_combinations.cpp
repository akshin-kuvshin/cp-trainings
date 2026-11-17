// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const lli MOD = 1'000'000'007LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<lli> dp(n + 1);
    dp.front() = 1LL;
    for (int i = 1; i <= n; ++i)
        for (int di = 1; di <= min(6, i); ++di)
            dp[i] = (dp[i] + dp[i - di]) % MOD;

    cout << dp.back() << '\n';
}
