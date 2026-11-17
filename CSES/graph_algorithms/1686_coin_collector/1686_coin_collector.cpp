// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long int lli;

void solve();
vector<vector<lli>> kosaraju(const vector<vector<lli>>& G, const vector<vector<lli>>& Gr, lli n);
void dfs1(lli v, const vector<vector<lli>>& G, vector<bool>& used, vector<lli>& order);
void dfs2(lli v, const vector<vector<lli>>& Gr, vector<lli>& color, lli c);
void topsort(lli css, const vector<unordered_set<lli>>& GC, vector<bool>& used, vector<lli>& order);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<lli> k(n);
    for (auto& k_i : k)
        cin >> k_i;
    vector<vector<lli>> G(n),
                        Gr(n);
    while (m--) {
        lli u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        Gr[v].push_back(u);
    }



    vector<vector<lli>> C = kosaraju(G, Gr, n);
    lli C_size = (lli)C.size();

    vector<lli> coins(C_size);
    vector<lli> pos(n); // pos[v] = в какой css лежит вершина v
    for (lli css = 0LL; css < C_size; ++css)
        for (auto v : C[css]) {
            coins[css] += k[v];
            pos[v] = css;
        }

    vector<unordered_set<lli>> GC(C_size);
    for (lli css = 0LL; css < C_size; ++css)
        for (auto v : C[css])
            for (auto nb : G[v]) {
                if (pos[nb] == pos[v])
                    continue;
                GC[css].insert(pos[nb]);
            }



    vector<bool> used(C_size);
    vector<lli> order;
    for (lli css = 0LL; css < C_size; ++css) {
        if (used[css])
            continue;
        topsort(css, GC, used, order);
    }
    reverse(order.begin(), order.end());

    vector<lli> dp = coins; // dp[css] = макс. кол-во монет, которое можно собрать, закончив свой путь в css
    for (auto css : order)
        for (auto nb : GC[css])
            dp[nb] = max(dp[nb], dp[css] + coins[nb]);

    lli ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
}

vector<vector<lli>> kosaraju(const vector<vector<lli>>& G, const vector<vector<lli>>& Gr, lli n) {
    vector<bool> used(n);
    vector<lli> order;
    for (lli v = 0LL; v < n; ++v) {
        if (used[v])
            continue;
        dfs1(v, G, used, order);
    }
    reverse(order.begin(), order.end());

    vector<lli> color(n, -1LL);
    lli cnt = 0LL;
    for (auto v : order) {
        if (color[v] >= 0LL)
            continue;
        dfs2(v, Gr, color, cnt++);
    }

    vector<vector<lli>> C(cnt);
    for (lli v = 0LL; v < n; ++v)
        C[color[v]].push_back(v);
    return C;
}

void dfs1(lli v, const vector<vector<lli>>& G, vector<bool>& used, vector<lli>& order) {
    used[v] = true;
    for (auto nb : G[v]) {
        if (used[nb])
            continue;
        dfs1(nb, G, used, order);
    }
    order.push_back(v);
}

void dfs2(lli v, const vector<vector<lli>>& Gr, vector<lli>& color, lli c) {
    color[v] = c;
    for (auto nb : Gr[v]) {
        if (color[nb] >= 0LL)
            continue;
        dfs2(nb, Gr, color, c);
    }
}

void topsort(lli css, const vector<unordered_set<lli>>& GC, vector<bool>& used, vector<lli>& order) {
    used[css] = true;
    for (auto nb : GC[css]) {
        if (used[nb])
            continue;
        topsort(nb, GC, used, order);
    }
    order.push_back(css);
}
