// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
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
        m;
    cin >> n >> m;
    vector<vector<lli>> a(n, vector<lli>(m));
    for (auto& row : a)
        for (auto& elem : row)
            cin >> elem;

    lli ans = 0LL;
    lli l = 0LL,
        r = n - 1LL;
    while (l < r) {
        const auto& a1 = a[l];
        const auto& a2 = a[r];

        lli i = 0LL,
            j = m - 1LL;
        while (i < j) {
            unordered_map<lli, lli> mm;
            ++mm[a1[i]];
            ++mm[a1[j]];
            ++mm[a2[i]];
            ++mm[a2[j]];

            if (mm.size() == 4LL)
                ans += 3LL;
            else if (mm.size() == 2LL and mm.begin()->second != 2LL)
                ans += 1LL;
            else if (mm.size() != 1LL)
                ans += 2LL;

            ++i; --j;
        }
        if (i == j and a1[i] != a2[i])
            ++ans;

        ++l; --r;
    }
    if (l == r) {
        lli i = 0LL,
            j = m - 1LL;
        while (i < j) {
            ans += (lli)(a[l][i] != a[l][j]);
            ++i; --j;
        }
    }

    cout << ans << '\n';
}
