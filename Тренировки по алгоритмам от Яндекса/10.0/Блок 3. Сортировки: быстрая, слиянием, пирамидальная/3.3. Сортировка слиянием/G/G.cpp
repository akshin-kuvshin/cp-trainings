// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef vector<lli>::iterator it;
typedef vector<lli>::const_iterator cit;

void solve();
void mergesort(vector<lli>& arr, lli n);
void merge_(cit a_begin, cit a_end, cit b_begin, cit b_end, it c_begin);

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

    mergesort(a, n);

    for (auto& a_i : a)
        cout << a_i << ' ';
    cout << '\n';
}

void mergesort(vector<lli>& arr, lli n) {
    vector<lli> tmp(n);

    vector<lli>* a = &arr;
    vector<lli>* buf = &tmp;
    for (lli d = 1LL; d < n; d <<= 1) {
        lli l;
        for (l = 0LL; l + d < n; l += (d << 1))
            merge_(a->begin() + l, a->begin() + l + d, a->begin() + l + d, a->begin() + min(l + (d << 1), n), buf->begin() + l);
        for (; l < n; ++l)
            (*buf)[l] = (*a)[l];
        swap(a, buf);
    }

    if (a != &arr)
        arr = tmp;
}

void merge_(cit a_begin, cit a_end, cit b_begin, cit b_end, it c_begin) {
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
