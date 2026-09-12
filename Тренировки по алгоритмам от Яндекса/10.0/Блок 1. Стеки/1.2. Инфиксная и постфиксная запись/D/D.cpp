// author: Danila "akshin_" Axyonov

#include <iostream>
#include <sstream>
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
    getline(cin, s);
    stringstream ss;
    ss << s;
    stack<lli> st;
    while (not ss.eof()) {
        char c;
        ss >> c;
        if ('0' <= c and c <= '9') {
            st.push((lli)(c - '0'));
            continue;
        }
        if ((lli)st.size() < 2LL)
            break;
        lli a,
            b;
        b = st.top(); st.pop();
        a = st.top(); st.pop();
        if (c == '+')
            st.push(a + b);
        else if (c == '-')
            st.push(a - b);
        else // c == '*'
            st.push(a * b);
    }
    cout << st.top() << '\n';
}
