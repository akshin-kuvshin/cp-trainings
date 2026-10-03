// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        w;
    cin >> n >> w;
    vector<tuple<lli, lli, lli>> a(n); // (x, w, i)
    for (int i = 0; i < (int)n; ++i) {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<2>(a[i]) = (lli)i + 1LL;
    }

    sort(a.begin(), a.end());

    vector<vector<lli>> layers;
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    layers.pb({ get<2>(a.front()) });
    pq.push(mp(get<0>(a.front()) + get<1>(a.front()), 0LL));
    for (int i = 1; i < (int)n; ++i) {
        if (pq.top().first <= get<0>(a[i])) {
            auto p = pq.top();
            pq.pop();
            p.first = get<0>(a[i]) + get<1>(a[i]);
            layers[p.second].pb(get<2>(a[i]));
            pq.push(p);
        } else { // get<0>(a[i]) < pq.top().first
            layers.pb({ get<2>(a[i]) });
            pq.push(mp(get<0>(a[i]) + get<1>(a[i]), (lli)layers.size() - 1LL));
        }
    }

    cout << layers.size() << '\n'; // MAZAFAKA
    for (const auto& layer : layers)
        for (auto ind : layer)
            cout << ind << ' ';
    cout << '\n';
}
