// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 5LL;
const lli NOT_ = INF;
const lli AND_ = NOT_ + 1LL,
          OR_ = NOT_ + 2LL,
          XOR_ = NOT_ + 3LL;

void solve();
lli digit(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    unordered_map<char, lli> priority;
    priority['|'] = priority['^'] = 0LL;
    priority['&'] = 1LL;
    priority['!'] = 2LL;
    unordered_map<char, lli> code;
    code['!'] = NOT_;
    code['&'] = AND_;
    code['|'] = OR_;
    code['^'] = XOR_;

    string s;
    getline(cin, s);
    lli s_size = (lli)s.size();

    vector<lli> rbkn; // reverse bobr kurwa notation
    stack<pair<char, lli>> ops;
    for (int i = 0; i < (int)s_size; ++i) {
        if (digit(s[i]) != -1LL)
            rbkn.pb(digit(s[i]));
        else if (priority.contains(s[i])) {
            while (not ops.empty() and ops.top().first != '(' and priority[s[i]] <= ops.top().second) {
                rbkn.pb(code[ops.top().first]);
                ops.pop();
            }
            ops.push(mp(s[i], priority[s[i]]));
        } else if (s[i] == '(')
            ops.push(mp('(', INF));
        else { // s[i] == ')'
            while (ops.top().first != '(') {
                rbkn.pb(code[ops.top().first]);
                ops.pop();
            }
            ops.pop();
        }
    }
    while (not ops.empty()) {
        rbkn.pb(code[ops.top().first]);
        ops.pop();
    }

    stack<lli> st;
    for (lli n : rbkn)
        if (n < INF)
            st.push(n);
        else {
            lli b = st.top(); st.pop();
            if (n == NOT_) {
                st.push(1LL - b);
                continue;
            }
            lli a = st.top(); st.pop();
            if (n == AND_)
                st.push(a * b);
            else if (n == OR_)
                st.push(1LL - (1LL - a) * (1LL - b));
            else // n == XOR_
                st.push((a + b) % 2LL);
        }
    cout << st.top() << '\n';
}

lli digit(char c) {
    if (c == '0')
        return 0LL;
    if (c == '1')
        return 1LL;
    return -1LL;
}
