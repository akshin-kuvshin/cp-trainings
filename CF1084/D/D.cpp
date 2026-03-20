// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y;

    vector<int> p(n);
    for (auto& pi : p)
        cin >> pi;

    vector<int> p_inside,
                p_outside;
    for (int i = 0; i < n; ++i)
        ((x < i and i <= y) ? p_inside : p_outside).push_back(p[i]);

    auto p_inside_min_ptr = min_element(p_inside.begin(), p_inside.end());

    for (auto& pi : p_outside) {
        if (pi > *p_inside_min_ptr)
            break;
        cout << pi << ' ';
        pi = -1;
    }
    for (auto it = p_inside_min_ptr; it != p_inside.end(); ++it)
        cout << *it << ' ';
    for (auto it = p_inside.begin(); it != p_inside_min_ptr; ++it)
        cout << *it << ' ';
    for (auto pi : p_outside) {
        if (pi == -1)
            continue;
        cout << pi << ' ';
    }
    cout << '\n';
}
