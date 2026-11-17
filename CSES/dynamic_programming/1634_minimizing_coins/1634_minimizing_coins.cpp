// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1'000'000'001;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n,
        x;
    cin >> n >> x;
    vector<int> c(n);
    for (auto& c_i : c)
        cin >> c_i;
    sort(c.begin(), c.end());

    vector<int> dp(x + 1, INF);
    dp.front() = 0;
    for (int i = 1; i <= x; ++i)
        for (auto c_j : c) {
            if (i - c_j < 0)
                break;
            dp[i] = min(dp[i], dp[i - c_j] + 1);
        }

    cout << (dp.back() == INF ? -1 : dp.back()) << '\n';
}
