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
    vector<lli> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<lli> ans(n);
    stack<pair<lli, lli>> st;
    for (int i = 0; i < (int)n; ++i) {
        while (not st.empty() and st.top().first > a[i]) {
            ans[st.top().second] = (lli)i;
            st.pop();
        }
        st.push(mp(a[i], (lli)i));
    }
    while (not st.empty()) {
        ans[st.top().second] = -1LL;
        st.pop();
    }

    for (auto ansi : ans)
        cout << ansi << ' ';
    cout << '\n';
}
