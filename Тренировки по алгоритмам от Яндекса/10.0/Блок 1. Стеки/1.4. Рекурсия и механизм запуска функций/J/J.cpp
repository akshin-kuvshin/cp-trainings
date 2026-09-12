// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void move(lli n, lli from, lli to);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    move(n, 1LL, 3LL);
}

void move(lli n, lli from, lli to) {
    if (n == 1LL) {
        cout << "1 " << from << ' ' << to << '\n';
        return;
    }
    lli tmp = 6LL - from - to;
    move(n - 1LL, from, tmp);
    cout << n << ' ' << from << ' ' << to << '\n';
    move(n - 1LL, tmp, to);
}
