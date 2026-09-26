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
    lli n,
        k;
    cin >> n >> k;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;

    deque<plli> dq;
    lli i = 0LL;
    while (i < k) {
        while (not dq.empty() and dq.back().first > a[i])
            dq.pop_back();
        dq.push_back(mp(a[i], i));
        ++i;
    }
    cout << dq.front().first << '\n';
    while (i < n) {
        while (not dq.empty() and dq.back().first > a[i])
            dq.pop_back();
        dq.push_back(mp(a[i], i));
        if (dq.front().second == i - k)
            dq.pop_front();
        cout << dq.front().first << '\n';
        ++i;
    }
}
