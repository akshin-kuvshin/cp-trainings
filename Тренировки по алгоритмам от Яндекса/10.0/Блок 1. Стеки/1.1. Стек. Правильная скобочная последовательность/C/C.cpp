// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
bool is_letter(char c);
void correct(string& s, char type = '\0');

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    string s;
    cin >> s;
    lli s_size = (lli)s.size(),
        open_brackets = (lli)count(s.begin(), s.end(), '<'), // 2k
        close_brackets = (lli)count(s.begin(), s.end(), '>'), // 2k
        slashs = (lli)count(s.begin(), s.end(), '/'); // k

    if (open_brackets & 1LL and close_brackets & 1LL) {
        if (open_brackets < close_brackets) { // '<' -> '>'
            if (s.front() == '>')
                s.front() = '<';
            else for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] == '>' and s[i + 1] == '>') {
                    s[i + 1] = '<';
                    break;
                }
        } else { // close_brackets < open_brackets // '>' -> '<'
            if (s.back() == '<')
                s.back() = '>';
            else for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] == '<' and s[i + 1] == '<') {
                    s[i] = '>';
                    break;
                }
        }
    } else if (open_brackets & 1LL) {
        if ((slashs - 1LL) * 2LL == close_brackets) { // '<' -> '/'
            if (s.front() == '/')
                s.front() = '<';
            else for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] == '>' and s[i + 1] == '/') {
                    s[i + 1] = '<';
                    break;
                }
        } else if (slashs * 2LL == close_brackets) {
            if (open_brackets < close_brackets) { // '<' -> 'a'
                if (is_letter(s.front()))
                    s.front() = '<';
                else for (int i = 0; i + 1 < (int)s_size; ++i)
                    if (s[i] == '>' and is_letter(s[i + 1])) {
                        s[i + 1] = '<';
                        break;
                    }
            } else { // open_brackets > close_brackets // 'a' -> '<'
                for (int i = 0; i + 1 < (int)s_size; ++i)
                    if (s[i] != '>' and s[i + 1] == '<') {
                        s[i + 1] = '?';
                        break;
                    }
                correct(s, '?');
            }
        } else { // (slashs + 1LL) * 2LL == close_brackets // '/' -> '<'
            for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] == '<' and s[i + 1] == '<') {
                    s[i + 1] = '/';
                    break;
                }
        }
    } else if (close_brackets & 1LL) {
        if ((slashs - 1LL) * 2LL == open_brackets) { // '>' -> '/'
            if (s.back() == '/')
                s.back() = '>';
            else for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] == '/' and s[i + 1] == '<') {
                    s[i] = '>';
                    break;
                }
        } else if (slashs * 2LL == open_brackets) {
            if (close_brackets < open_brackets) { // '>' -> 'a'
                if (is_letter(s.back()))
                    s.back() = '>';
                else for (int i = 0; i + 1 < (int)s_size; ++i)
                    if (is_letter(s[i]) and s[i + 1] == '<')
                        s[i] = '>';
            } else { // close_brackets > open_brackets // 'a' -> '>'
                for (int i = 0; i + 1 < (int)s_size; ++i)
                    if (s[i] == '>' and s[i + 1] != '<') {
                        s[i] = '?';
                        break;
                    }
                correct(s, '?');
            }
        } else { // (slashs + 1LL) * 2LL == open_brackets // '/' -> '>'
            for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] == '<' and s[i + 1] == '>') {
                    s[i + 1] = '/';
                    break;
                }
        }
    } else {
        if ((slashs + 1LL) * 2LL == open_brackets) { // '/' -> 'a'
            correct(s, 'o');
        } else if ((slashs - 1LL) * 2LL == open_brackets) { // 'a' -> '/'
            char type = 'c';
            for (int i = 0; i + 1 < (int)s_size; ++i)
                if (s[i] != '<' and s[i + 1] == '/') {
                    s[i + 1] = '?';
                    type = '?';
                    break;
                }
            correct(s, type);
        } else { // slashs * 2LL == open_brackets // 'a' -> 'b'
            correct(s);
        }
    }

    cout << s << '\n';
}

bool is_letter(char c) {
    return 'a' <= c and c <= 'z';
}

void correct(string& s, char type) {
    struct tag {
        string name;
        bool open;
        bool close;
        bool cq; // contains question sign
        lli b;
        lli e;

        tag(const string& s, lli init_b, lli init_e) {
            b = init_b;
            e = init_e;
            if (s[b + 1LL] == '/') {
                name = s.substr(b + 2LL, e - b - 3LL);
                open = false;
                close = true;
            } else { // is_letter(s[b + 1LL])
                name = s.substr(b + 1LL, e - b - 2LL);
                open = true;
                close = false;
            }
            cq = (name.find('?') != string::npos);
        }

        bool closes(const tag& t) const {
            if (t.close or open)
                return false;
            return t.name == name;
        }
    };

    vector<lli> split_inds = {0LL};
    for (int i = 0; i + 1 < (int)s.size(); ++i)
        if (s[i] == '>' and s[i + 1] == '<')
            split_inds.pb((lli)(i + 1));
    split_inds.pb((lli)s.size());

    vector<tag> tags;
    for (int i = 0; i + 1 < (int)split_inds.size(); ++i)
        tags.emplace_back(s, split_inds[i], split_inds[i + 1]);

    vector<tag> st;
    for (auto tag : tags) {
        if (tag.open)
            st.pb(tag);
        else { // tag.close
            if (not st.empty() and tag.closes(st.back()))
                st.pop_back();
            else
                st.pb(tag);
        }
    }

    lli k = (lli)st.size() / 2LL - 1LL;
    switch (type) {
    case '?':
        if (st[k].cq)
            for (int i = 0; i < (int)st[k].name.size(); ++i)
                s[st[k].b + 1LL + (lli)i] = st[k + 1LL].name[i];
        else // st[k + 1LL].cq
            for (int i = 0; i < (int)st[k].name.size(); ++i)
                s[st[k + 1LL].b + 2LL + (lli)i] = st[k].name[i];
        break;

    case 'o':
        s[st[k + 1LL].b + 1LL] = '/';
        break;

    case 'c':
        s[st[k].b + 1LL] = st[k + 1LL].name.front();
        break;

    default:
        for (int i = 0; i < (int)st[k].name.size(); ++i)
           s[st[k].b + 1LL + (lli)i] = st[k + 1LL].name[i];
    }
}
