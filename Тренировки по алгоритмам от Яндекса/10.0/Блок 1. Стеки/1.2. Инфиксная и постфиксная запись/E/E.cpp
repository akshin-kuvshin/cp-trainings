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
const lli PLUS = INF;
const lli MINUS = PLUS + 1LL,
          PROD = PLUS + 2LL;

void solve();
bool is_digit(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    unordered_map<char, lli> priority;
    priority['+'] = priority['-'] = 0LL;
    priority['*'] = 1LL;
    unordered_map<char, lli> code;
    code['+'] = PLUS;
    code['-'] = MINUS;
    code['*'] = PROD;

    string s;
    getline(cin, s);
    s.pb(' ');
    lli s_size = (lli)s.size();

    vector<lli> rbkn; // reverse bobr kurwa notation
    stack<pair<char, lli>> ops;
    for (int i = 0; i < (int)s_size; ++i) {
        if (is_digit(s[i])) {
            lli num = 0LL;
            do {
                num = num * 10LL + (lli)(s[i] - '0');
                ++i;
            } while (is_digit(s[i]));
            --i;
            rbkn.pb(num);
        } else if (priority.contains(s[i])) {
            while (not ops.empty() and ops.top().first != '(' and priority[s[i]] <= ops.top().second) {
                rbkn.pb(code[ops.top().first]);
                ops.pop();
            }
            ops.push(mp(s[i], priority[s[i]]));
        } else if (s[i] == '(')
            ops.push(mp('(', INF));
        else if (s[i] == ')') {
            while (not ops.empty() and ops.top().first != '(') {
                rbkn.pb(code[ops.top().first]);
                ops.pop();
            }
            if (ops.empty()) {
                cout << "WRONG\n";
                return;
            }
            ops.pop();
        } else if (s[i] != ' ') {
            cout << "WRONG\n";
            return;
        }
    }
    while (not ops.empty()) {
        if (ops.top().first == '(') {
            cout << "WRONG\n";
            return;
        }
        rbkn.pb(code[ops.top().first]);
        ops.pop();
    }

    stack<lli> st;
    for (lli n : rbkn)
        if (n < INF)
            st.push(n);
        else {
            if ((lli)st.size() < 2LL) {
                cout << "WRONG\n";
                return;
            }
            lli b = st.top(); st.pop();
            lli a = st.top(); st.pop();
            if (n == PLUS)
                st.push(a + b);
            else if (n == MINUS)
                st.push(a - b);
            else // n == PROD
                st.push(a * b);
        }
    if ((lli)st.size() > 1LL) {
        cout << "WRONG\n";
        return;
    }
    cout << st.top() << '\n';
}

bool is_digit(char c) {
    return '0' <= c and c <= '9';
}
