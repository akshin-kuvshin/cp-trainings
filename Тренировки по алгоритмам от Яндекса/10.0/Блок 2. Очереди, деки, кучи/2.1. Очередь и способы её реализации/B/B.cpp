// author: Danila "akshin_" Axyonov

#include <iostream>
#include <queue>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N = 5LL,
          STEP_MAX = 1'000'000LL,
          MIN_ = 0LL,
          MAX_ = 9LL;

void solve();
bool get_winner(lli a, lli b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    queue<lli> q[2]; {
        lli tmp;
        for (int _ = 0; _ < (int)N; ++_) {
            cin >> tmp;
            q[0].push(tmp);
        }
        for (int _ = 0; _ < (int)N; ++_) {
            cin >> tmp;
            q[1].push(tmp);
        }
    }

    lli step = 0LL;
    while (step <= STEP_MAX and not q[0].empty() and not q[1].empty()) {
        lli a = q[0].front(); q[0].pop();
        lli b = q[1].front(); q[1].pop();
        bool winner = get_winner(a, b);
        q[winner].push(a);
        q[winner].push(b);
        ++step;
    }

    if (q[0].empty())
        cout << "second " << step;
    else if (q[1].empty())
        cout << "first " << step;
    else // step > STEP_MAX
        cout << "botva";
    cout << '\n';
}

bool get_winner(lli a, lli b) {
    if (a == MIN_ and b == MAX_)
        return false; // 0
    if (a == MAX_ and b == MIN_)
        return true; // 1
    return a < b;
}
