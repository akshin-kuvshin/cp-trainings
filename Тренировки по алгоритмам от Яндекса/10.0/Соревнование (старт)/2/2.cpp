// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli KOLYA = 501LL;

void solve();
bool check(const vector<lli>& cnt_s, const vector<lli>& cnt_t);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    string s,
           t;
    cin >> s >> t;
    lli s_size = (lli)s.size();

    vector<lli> cnt_s(KOLYA),
                cnt_t(KOLYA);
    for (char c : t)
        ++cnt_t[c];

    lli l = 0LL,
        r = 0LL,
        ans = 0LL;
    while (l < s_size) {
        while (r < s_size and check(cnt_s, cnt_t))
            ++cnt_s[s[r++]];
        ans += r - l - 1LL;
        if (check(cnt_s, cnt_t))
            ++ans;
        --cnt_s[s[l++]];
    }

    cout << ans << '\n';
}

bool check(const vector<lli>& cnt_s, const vector<lli>& cnt_t) {
    for (char c = 'a'; c <= 'z'; ++c)
        if (cnt_s[c] > cnt_t[c])
            return false;
    return true;
}
