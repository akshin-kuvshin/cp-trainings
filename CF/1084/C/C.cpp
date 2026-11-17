// author: Danila "akshin_" Axyonov

#include <iostream>
#include <stack>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--)
        solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    char c;
    stack<char> st;
    while (n--) {
        cin >> c;
        if (not st.empty() and st.top() == c)
            st.pop();
        else
            st.push(c);
    }

    cout << (st.empty() ? "YES" : "NO") << '\n';
}
