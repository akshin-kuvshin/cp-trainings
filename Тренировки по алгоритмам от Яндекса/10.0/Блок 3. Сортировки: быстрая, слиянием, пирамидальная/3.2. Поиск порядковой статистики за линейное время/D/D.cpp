// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> x(n),
                y(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int k = (int)(n >> 1);
    lli ans = 0LL;
    for (auto y_i : y)
        ans += abs(y[k] - y_i);

    for (lli a = n; a >= 1LL; --a) {
        ans += abs(a - x.back());
        x.pop_back();
    }

    cout << ans << '\n';
}
