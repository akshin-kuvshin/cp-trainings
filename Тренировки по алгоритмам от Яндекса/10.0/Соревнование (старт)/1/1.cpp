// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
bool is_lower(char c);
char to_lower(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        lli s_size = (lli)s.size();
        cout << to_lower(s[0]);
        for (int i = 1; i < (int)s_size; ++i) {
            if (not is_lower(s[i]))
                cout << '_';
            cout << to_lower(s[i]);
        }
        cout << '\n';
    }
}

bool is_lower(char c) {
    return 'a' <= c and c <= 'z';
}

char to_lower(char c) {
    if ('A' <= c and c <= 'Z')
        c = 'a' + (c - 'A');
    return c;
}
