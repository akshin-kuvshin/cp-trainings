// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli D = 4LL;

struct rover {
    lli d;
    lli t;
    lli i;

    bool operator<(const rover& r) const {
        if (t != r.t)
            return t < r.t;
        return i < r.i;
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        a,
        b;
    cin >> n >> a >> b;
    --a; --b;
    vector<rover> r(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> r[i].d >> r[i].t;
        --r[i].d;
        r[i].i = (lli)i;
    }
    sort(r.begin(), r.end());
    lli top = 0LL;

    vector<lli> ans(n);
    queue<lli> q[D];
    lli t = 1LL;
    if (abs(a - b) == 2LL) {
        while (top < n or any_of(q, q + D, [](const queue<lli>& qq) { return not qq.empty(); })) {
            while (top < n and r[top].t == t) {
                q[r[top].d].push(r[top].i);
                ++top;
            }

            bool main = false;
            if (not q[a].empty()) {
                ans[q[a].front()] = t;
                q[a].pop();
                main = true;
            }
            if (not q[b].empty()) {
                ans[q[b].front()] = t;
                q[b].pop();
                main = true;
            }

            if (not main) {
                if (not q[(a + 1LL) % D].empty()) {
                    ans[q[(a + 1LL) % D].front()] = t;
                    q[(a + 1LL) % D].pop();
                }
                if (not q[(b + 1LL) % D].empty()) {
                    ans[q[(b + 1LL) % D].front()] = t;
                    q[(b + 1LL) % D].pop();
                }
            }

            ++t;
        }
    } else { // abs(a - b) & 1LL
        vector<lli> priority;
        if (a + b == D - 1LL and a * b == 0LL) {
            priority.pb(D - 1LL);
            priority.pb(0LL);
        } else {
            priority.pb(min(a, b));
            priority.pb(max(a, b));
        }
        while ((lli)priority.size() < D)
            priority.pb((priority.back() + 1LL) % D);

        while (top < n or any_of(q, q + D, [](const queue<lli>& qq) { return not qq.empty(); })) {
            while (top < n and r[top].t == t) {
                q[r[top].d].push(r[top].i);
                ++top;
            }

            for (auto p : priority)
                if (not q[p].empty()) {
                    ans[q[p].front()] = t;
                    q[p].pop();
                    break;
                }

            ++t;
        }
    }

    for (auto ans_i : ans)
        cout << ans_i << '\n';
}
