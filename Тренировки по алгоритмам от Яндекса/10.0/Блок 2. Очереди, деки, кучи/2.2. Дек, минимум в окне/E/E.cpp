// author: Danila "akshin_" Axyonov

#include <iostream>
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

    deque<lli> a,
               b;
    char cmd;
    lli i;
    while (n--) {
        cin >> cmd;

        if (cmd == '+') {
            cin >> i;
            b.push_back(i);
        } else if (cmd == '*') {
            cin >> i;
            b.push_front(i);
        } else { // cmd == '-'
            cout << a.front() << '\n';
            a.pop_front();
        }

        while ((lli)(a.size() - b.size()) > 1LL) {
            b.push_front(a.back());
            a.pop_back();
        }
        while (a.size() < b.size()) {
            a.push_back(b.front());
            b.pop_front();
        }
    }
}
