// author: Danila "akshin_" Axyonov

#include <iostream>
#include <map>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        k;
    cin >> n >> k;
    map<lli, lli> m;
    while (n--) {
        lli a_i;
        cin >> a_i;
        ++m[a_i];
    }

    lli ans = 0LL;
    for (auto [val, cnt] : m) {
        if (val > k - val)
            break;
        if (val == k - val)
            ans += cnt - 1LL;
        else // val < k - val
            ans += min(cnt, m[k - val]);
    }
    cout << ans << '\n';
}
