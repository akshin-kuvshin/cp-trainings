// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
double bin_pow(double base, lli ptr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    double a;
    lli n;
    cin >> a >> n;
    double ans = bin_pow(a, n);
    cout << fixed << setprecision(20) << ans << '\n';
}

double bin_pow(double base, lli ptr) {
    if (ptr < 0LL)
        return 1. / bin_pow(base, -ptr);
    if (ptr == 0LL)
        return 1.;
    if (ptr & 1LL)
        return base * bin_pow(base, ptr - 1LL);
    double half = bin_pow(base, ptr / 2LL);
    return half * half;
}
