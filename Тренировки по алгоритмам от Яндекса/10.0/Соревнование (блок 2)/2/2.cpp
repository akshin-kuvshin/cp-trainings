// author: Danila "akshin_" Axyonov

#include <iostream>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
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
    deque<pair<string, lli>> dq; {
        string name;
        lli len;
        while (n--) {
            cin >> name >> len;
            dq.push_back(mp(name, len));
        }
    }
    lli m;
    cin >> m;
    queue<tuple<lli, string, lli>> q; {
        lli t;
        string name;
        lli len;
        while (m--) {
            cin >> t >> name >> len;
            q.push(make_tuple(t, name, len));
        }
    }

    lli t = 0LL;
    while (not dq.empty() or not q.empty()) {
        while (not q.empty() and get<0>(q.front()) <= t) {
            dq.push_front(mp(
                get<1>(q.front()),
                get<2>(q.front())
            ));
            q.pop();
        }

        if (not dq.empty()) {
            auto [name, len] = dq.front();
            dq.pop_front();
            cout << name << ' ' << t << '\n';
            t += len;
        } else // dq.empty()
            t = get<0>(q.front());
    }
}
