// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
    vector<vector<char>> a(n, vector<char>(m));
    for (auto& row : a)
        for (auto& c : row)
            cin >> c;

    vector<vector<lli>> row(n),
                        col(m);
    lli len;
    for (int i = 0; i < (int)n; ++i) {
        len = 0LL;
        for (int j = 0; j < (int)m; ++j)
            if (a[i][j] == '#')
                ++len;
            else /* a[i][j] == '.' */ if (len) {
                row[i].pb(len);
                len = 0LL;
            }
        if (len)
            row[i].pb(len);
    }
    for (int j = 0; j < (int)m; ++j) {
        len = 0LL;
        for (int i = 0; i < (int)n; ++i)
            if (a[i][j] == '#')
                ++len;
            else /* a[i][j] == '.' */ if (len) {
                col[j].pb(len);
                len = 0LL;
            }
        if (len)
            col[j].pb(len);
    }

    for (int i = 0; i < (int)n; ++i) {
        cout << row[i].size();
        for (auto len_ : row[i])
            cout << ' ' << len_;
        cout << '\n';
    }
    cout << '\n';
    for (int j = 0; j < (int)m; ++j) {
        cout << col[j].size();
        for (auto len_ : col[j])
            cout << ' ' << len_;
        cout << '\n';
    }
}
