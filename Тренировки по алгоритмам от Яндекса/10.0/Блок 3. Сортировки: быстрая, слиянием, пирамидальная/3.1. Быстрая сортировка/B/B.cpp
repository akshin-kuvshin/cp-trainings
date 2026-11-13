// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef vector<lli>::iterator vlliit;
typedef pair<vlliit, vlliit> pvlliit;

void solve();
void quick_sort(vlliit begin, vlliit end);
pvlliit partition(vlliit begin, vlliit end, lli pivot);

int main() {
    srand((unsigned)time(nullptr));

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

    quick_sort(a.begin(), a.end());

    for (auto a_i : a)
        cout << a_i << ' ';
    cout << '\n';
}

void quick_sort(vlliit begin, vlliit end) {
    lli d = (lli)(end - begin);
    if (d < 2LL)
        return;
    lli pivot = *(begin + (lli)rand() % d);
    auto [it1, it2] = partition(begin, end, pivot);
    quick_sort(begin, it1);
    quick_sort(it2, end);
}

pvlliit partition(vlliit begin, vlliit end, lli pivot) {
    auto e = begin,
         g = begin;
    while (begin != end) {
        if (*begin < pivot) {
            swap(*e, *begin);
            if (e != g)
                swap(*g, *begin);
            ++e;
            ++g;
        } else if (*begin == pivot) {
            swap(*g, *begin);
            ++g;
        }
        ++begin;
    }
    return make_pair(e, g);
}
