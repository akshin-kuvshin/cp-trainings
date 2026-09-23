// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void dfs(lli i, lli open, lli close, lli slash, unordered_map<char, lli>& letters);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    string s;
    cin >> s;

    lli open = 0LL,
        close = 0LL,
        slash = 0LL;
    unordered_map<char, lli> letters;
    for (char c : s)
        if (c == '<')
            ++open;
        else if (c == '>')
            ++close;
        else if (c == '/')
            ++slash;
        else
            ++letters[c];
    lli letters_total = 0LL;

    for (auto [c, cnt] : letters) {
        if (cnt & 1LL) {
            cout << "Impossible\n";
            return;
        }
        letters_total += cnt;
    }
    if (not (slash > 0LL and open == slash << 1 and close == slash << 1 and open <= letters_total)) {
        cout << "Impossible\n";
        return;
    }

    dfs(1LL, open, close, slash, letters);
    cout << '\n';
}

void dfs(lli i, lli open, lli close, lli slash, unordered_map<char, lli>& letters) {
    if (i > slash)
        return;

    string tag;
    if (i == slash)
        for (auto [c, cnt] : letters) {
            lli half = cnt >> 1;
            while (half--)
                tag.push_back(c);
        }
    else // i < slash
        tag = letters.begin()->first;
    string to_delete;
    for (char c : tag) {
        letters[c] -= 2LL;
        if (not letters[c])
            to_delete.push_back(c);
    }
    for (char c : to_delete)
        letters.erase(c);

    cout << '<' << tag << '>';
    dfs(i + 1LL, open, close, slash, letters);
    cout << "</" << tag << '>';
}
