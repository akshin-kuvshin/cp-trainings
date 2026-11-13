// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

void solve();
vector<lli>::iterator partition(vector<lli>::iterator begin, vector<lli>::iterator end, lli pivot);

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
    lli pivot;
    cin >> pivot;

    auto it = partition(a.begin(), a.end(), pivot);
    lli l_size = (lli)(it - a.begin()),
        r_size = (lli)(a.end() - it);

    cout << l_size << '\n' << r_size << '\n';
}

vector<lli>::iterator partition(vector<lli>::iterator begin, vector<lli>::iterator end, lli pivot)
{
    auto it = begin;
    while (begin != end) {
        if (*begin < pivot) {
            swap(*it, *begin);
            ++it;
        }
        ++begin;
    }
    return it;
}
