// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
    vector<lli> p(n);

    lli a = 1LL;
    for (int i = (int)n - 1; i >= 0; i -= 2)
        p[i] = a++;
    a = n;
    for (int i = (int)n - 2; i >= 0; i -= 2)
        p[i] = a--;

    for (auto pi : p)
        cout << pi << ' ';
    cout << '\n';
}
