// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <stack>
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
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s)
        if (c == '(' or c == '[' or c == '{')
            st.push(c);
        else { // c == ')' or c == ']' or c == '}'
            if (st.empty()) {
                cout << "no\n";
                return;
            }
            char d = st.top();
            st.pop();
            if ((d == '(' and c == ')') or (d == '[' and c == ']') or (d == '{' and c == '}'))
                continue;
            cout << "no\n";
            return;
        }
    cout << (st.empty() ? "yes" : "no") << '\n';
}
