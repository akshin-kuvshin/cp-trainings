// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <deque>
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
    lli n;
    cin >> n;
    deque<lli> dq; {
        lli tmp;
        for (int i = 0; i < (int)n; ++i) {
            cin >> tmp;
            dq.push_back(tmp);
        }
    }

    vector<plli> short_ans(n + 1LL);
    lli game = 0LL;
    while (game < n) {
        lli a = dq.front(); dq.pop_front();
        lli b = dq.front(); dq.pop_front();
        dq.push_front(max(a, b));
        dq.push_back(min(a, b));
        short_ans[++game] = mp(a, b);
    }

    vector<lli> a;
    while (not dq.empty()) {
        a.pb(dq.front());
        dq.pop_front();
    }

    lli q;
    cin >> q;
    lli k;
    while (q--) {
        cin >> k;
        if (k <= n) {
            cout << short_ans[k].first << ' ' << short_ans[k].second << '\n';
            continue;
        }
        lli d = k - game;
        lli i = 1LL + (d - 1LL) % (n - 1LL);
        cout << a.front() << ' ' << a[i] << '\n';
    }
}
