// author: Danila "akshin_" Axyonov

#include <iostream>
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
    priority_queue<lli, vector<lli>, greater<lli>> pq; {
        lli tmp;
        while (n--) {
            cin >> tmp;
            pq.push(tmp);
        }
    }

    lli ans = 0LL;
    while ((lli)pq.size() > 1LL) {
        lli a = pq.top(); pq.pop();
        lli b = pq.top(); pq.pop();
        lli c = a + b;
        ans += c;
        pq.push(c);
    }
    ans *= 5LL;

    lli a = ans / 100LL,
        ns = ans % 100LL;
    cout << a << '.';
    if (ns == 0LL)
        cout << "00";
    else if (ns < 10LL)
        cout << '0' << ns;
    else // ns >= 10LL
        cout << ns;
    cout << '\n';
}
