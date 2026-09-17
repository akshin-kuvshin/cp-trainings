// author: Danila "akshin_" Axyonov

#include <iostream>
#include <stack>
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
    lli n;
    cin >> n;
    vector<lli> h(n);
    for (auto& hi : h)
        cin >> hi;

    vector<lli> r(n);
    stack<pair<lli, lli>> st;
    for (int i = 0; i < (int)n; ++i) {
        while (not st.empty() and st.top().first > h[i]) {
            r[st.top().second] = (lli)i;
            st.pop();
        }
        st.push(mp(h[i], (lli)i));
    }
    while (not st.empty()) {
        r[st.top().second] = n;
        st.pop();
    }

    vector<lli> l(n);
    for (int i = (int)n - 1; i >= 0; --i) {
        while (not st.empty() and st.top().first > h[i]) {
            l[st.top().second] = (lli)i;
            st.pop();
        }
        st.push(mp(h[i], (lli)i));
    }
    while (not st.empty()) {
        l[st.top().second] = -1LL;
        st.pop();
    }

    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i)
        ans = max(ans, h[i] * (r[i] - l[i] - 1LL));
    cout << ans << '\n';
}
