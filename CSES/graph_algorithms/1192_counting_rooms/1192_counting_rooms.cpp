// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pi;

void solve();
void dfs(int x, int y, const vector<vector<char>>& a, vector<vector<bool>>& used);
vector<pi> ns(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n,
        m;
    cin >> n >> m;
    vector<vector<char>> a(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    int rooms = 0;
    vector<vector<bool>> used(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '#' or used[i][j])
                continue;
            dfs(i, j, a, used);
            ++rooms;
        }

    cout << rooms << '\n';
}

void dfs(int x, int y, const vector<vector<char>>& a, vector<vector<bool>>& used) {
    used[x][y] = true;
    for (auto [nb_x, nb_y] : ns(x, y)) {
        if (a[nb_x][nb_y] == '#' or used[nb_x][nb_y])
            continue;
        dfs(nb_x, nb_y, a, used);
    }
}

vector<pi> ns(int x, int y) {
    return { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
}
