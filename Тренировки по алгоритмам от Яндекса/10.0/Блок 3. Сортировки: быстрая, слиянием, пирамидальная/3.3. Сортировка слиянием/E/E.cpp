// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef vector<lli>::iterator it;
typedef vector<lli>::const_iterator cit;

#define pb(_elem)           push_back(_elem)

void solve();
void merge(cit a_begin, cit a_end, cit b_begin, cit b_end, it c_begin);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;
    lli m;
    cin >> m;
    vector<lli> b(m);
    for (auto& b_i : b)
        cin >> b_i;

    vector<lli> c(n + m);
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    for (auto c_i : c)
        cout << c_i << ' ';
    cout << '\n';
}

void merge(cit a_begin, cit a_end, cit b_begin, cit b_end, it c_begin) {
    while (a_begin < a_end and b_begin < b_end)
        if (*a_begin <= *b_begin)
            *c_begin++ = *a_begin++;
        else // *b_begin < *a_begin
            *c_begin++ = *b_begin++;
    while (a_begin < a_end)
        *c_begin++ = *a_begin++;
    while (b_begin < b_end)
        *c_begin++ = *b_begin++;
}
