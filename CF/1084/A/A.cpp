// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--)
        solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    int mx = 0;
    for (auto ai : a)
        mx = max(mx, ai);

    int mx_cnt = 0;
    for (auto ai : a)
        mx_cnt += (ai == mx);
    cout << mx_cnt << '\n';
}
