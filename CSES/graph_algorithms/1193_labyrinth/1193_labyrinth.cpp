// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x first
#define y second

const pi NONE = mp(-1, -1),
         ROOT = mp(-52, -67);

void solve();
void bfs(pi start, const vector<vector<char>>& a, vector<vector<pi>>& p);
vector<pi> ns(int i, int j);
char mv(pi from, pi to);

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
    pi start,
       end;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                start = mp(i, j);
            else if (a[i][j] == 'B')
                end = mp(i, j);
        }

    vector<vector<pi>> p(n + 2, vector<pi>(m + 2, NONE));
    bfs(start, a, p);

    if (p[end.x][end.y] == NONE) {
        cout << "NO\n";
        return;
    }

    vector<char> path;
    for (pi v = end; p[v.x][v.y] != ROOT; v = p[v.x][v.y])
        path.pb(mv(p[v.x][v.y], v));
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.size() << '\n';
    for (char c : path)
        cout << c;
    cout << '\n';
}

void bfs(pi start, const vector<vector<char>>& a, vector<vector<pi>>& p) {
    queue<pi> q;
    p[start.x][start.y] = ROOT;
    q.push(start);
    while (not q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [nb_i, nb_j] : ns(i, j)) {
            if (a[nb_i][nb_j] == '#' or p[nb_i][nb_j] != NONE)
                continue;
            p[nb_i][nb_j] = mp(i, j);
            q.push(mp(nb_i, nb_j));
        }
    }
}

vector<pi> ns(int i, int j) {
    return { {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1} };
}

char mv(pi from, pi to) {
    if (from.x - 1 == to.x)
        return 'U';
    if (from.x + 1 == to.x)
        return 'D';
    if (from.y - 1 == to.y)
        return 'L';
    // if (from.y + 1 == to.y)
        return 'R';
}
