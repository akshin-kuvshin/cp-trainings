// author: Danila "akshin_" Axyonov
// в тупейшем еблище (тестирующей системе Яндекса для этой задачи) постоянно вылазит вердикт "Ошибка формата вывода (PE)"
// зато тут всё хорошо: https://informatics.mccme.ru/mod/statements/view.php?chapterid=541

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define mp(_first, _second) make_pair(_first, _second)
#define NONE 5267LL

const lli INF = (lli)1e18 + 1LL,
          N_MAX = 100LL;

void solve();
lli count_dist(const set<plli>& s, lli a, lli b);

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
    set<plli> s;
    for (int i = 0; i < (int)n; ++i) {
        cin >> x[i] >> y[i];
        s.insert(mp(x[i], y[i]));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int k = (int)(n >> 1);
    lli a = x[k],
        b = y[k]; // раньше здесь было x[k]...
    if ((n & 1LL) == 0LL)
        for (lli c = x[k - 1]; c <= x[k] and s.contains(mp(a, b)); ++c)
            for (lli d = y[k - 1]; d <= y[k]; ++d) {
                if (s.contains(mp(c, d)))
                    continue;
                a = c;
                b = d;
                break;
            }
    if (s.contains(mp(a, b))) {
        a = NONE;
        b = NONE;
        lli dist = INF;
        for (lli c = x[k] - N_MAX; c <= x[k] + N_MAX; ++c)
            for (lli d = y[k] - N_MAX; d <= y[k] + N_MAX; ++d) {
                if (s.contains(mp(c, d)))
                    continue;
                lli cur_dist = count_dist(s, c, d);
                if (cur_dist < dist) {
                    a = c;
                    b = d;
                    dist = cur_dist;
                }
            }
    }

    cout << a << ' ' << b << '\n';
}

lli count_dist(const set<plli>& s, lli a, lli b) {
    lli res = 0LL;
    for (auto [x, y] : s)
        res += abs(a - x) + abs(b - y);
    return res;
}
