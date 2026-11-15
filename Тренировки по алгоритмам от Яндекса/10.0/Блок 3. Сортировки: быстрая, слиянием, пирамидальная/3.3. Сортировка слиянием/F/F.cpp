// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
bool any_less(const vector<lli>& i, const vector<lli>& n);
void step(const vector<vector<lli>>& c, const vector<lli>& n, vector<lli>& i);
lli get_diff(vector<lli> f);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    vector<lli> n(4);
    vector<vector<lli>> c(4);
    for (int i = 0; i < 4; ++i) {
        cin >> n[i];
        c[i].resize(n[i]);
        for (auto& c_i_j : c[i])
            cin >> c_i_j;
        sort(c[i].begin(), c[i].end());
    }

    vector<lli> ans = {c[0].front(), c[1].front(), c[2].front(), c[3].front()};
    lli min_diff = get_diff(ans);
    vector<lli> i(4);
    while (any_less(i, n)) {
        step(c, n, i);
        vector<lli> f = {c[0][i[0]], c[1][i[1]], c[2][i[2]], c[3][i[3]]};
        lli cur_diff = get_diff(f);
        if (cur_diff < min_diff) {
            ans = f;
            min_diff = cur_diff;
        }
    }

    for (auto ans_i : ans)
        cout << ans_i << ' ';
    cout << '\n';
}

bool any_less(const vector<lli>& i, const vector<lli>& n) {
    for (int j = 0; j < 4; ++j)
        if (i[j] < n[j] - 1LL)
            return true;
    return false;
}

void step(const vector<vector<lli>>& c, const vector<lli>& n, vector<lli>& i) {
    vector<plli> cand;
    for (int j = 0; j < 4; ++j) {
        if (i[j] == n[j] - 1LL)
            continue;
        cand.pb(mp(c[j][i[j]], (lli)j));
    }
    sort(cand.begin(), cand.end());
    ++i[cand.front().second];
}

lli get_diff(vector<lli> f) {
    sort(f.begin(), f.end());
    return f.back() - f.front();
}
