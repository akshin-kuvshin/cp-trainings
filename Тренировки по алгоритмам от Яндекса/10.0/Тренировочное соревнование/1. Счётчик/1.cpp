// author: Danila "akshin_" Axyonov

#include <iostream>
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
    lli m,
        a,
        b;
    cin >> m >> a >> b;
    --a; --b;
    lli ans = b - a;
    if (b < a)
        ans += m;
    cout << ans << '\n';
}
