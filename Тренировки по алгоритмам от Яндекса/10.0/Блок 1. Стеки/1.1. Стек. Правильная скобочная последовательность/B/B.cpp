// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
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
    unordered_set<char> open,
                        close;
    open.insert('(');
    open.insert('[');
    close.insert(')');
    close.insert(']');

    unordered_map<char, char> open_pair,
                              close_pair;
    open_pair[')'] = '(';
    open_pair[']'] = '[';
    close_pair['('] = ')';
    close_pair['['] = ']';

    lli n;
    string w,
           s;
    cin >> n >> w >> s;

    stack<char> st;
    for (char c : s)
        if (open.contains(c))
            st.push(c);
        else // close.contains(c)
            st.pop();

    while ((lli)(s.size() + st.size()) < n)
        for (char c : w)
            if (open.contains(c)) {
                st.push(c);
                s.push_back(c);
                break;
            } else if (/* close.contains(c) and */ not st.empty() and st.top() == open_pair[c]) {
                st.pop();
                s.push_back(c);
                break;
            }
    while (not st.empty()) {
        char c = st.top();
        st.pop();
        s.push_back(close_pair[c]);
    }

    cout << s << '\n';
}
