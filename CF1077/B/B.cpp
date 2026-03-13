// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
typedef long long int lli;
using namespace std;

void solve();

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
    string s;
    cin >> s;
    s = "10" + s + "01";

    lli ans = 0LL,
        cur_len;
    for (auto c : s)
        if (c == '0')
            ++cur_len;
        else { // c == '1'
            ++ans;

            if (cur_len > 2LL)
                ans += cur_len / 3LL;
            cur_len = 0LL;
        }
    ans -= 2LL;

    cout << ans << '\n';
}
