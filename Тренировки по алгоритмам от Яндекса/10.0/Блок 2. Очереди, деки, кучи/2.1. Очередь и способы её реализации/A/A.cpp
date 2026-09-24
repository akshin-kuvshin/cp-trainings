// author: Danila "akshin_" Axyonov

#include <iostream>
#include <queue>
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
    queue<lli> q;

    string cmd;
    cin >> cmd;
    while (cmd != "exit") {
        if (cmd == "push") {
            lli n;
            cin >> n;
            q.push(n);
            cout << "ok" << endl;
        } else if (cmd == "pop" or cmd == "front") {
            if (not q.empty()) {
                cout << q.front() << endl;
                if (cmd == "pop")
                    q.pop();
            } else // q.empty()
                cout << "error" << endl;
        } else if (cmd == "size")
            cout << q.size() << endl;
        else { // cmd == "clear"
            q = queue<lli>();
            cout << "ok" << endl;
        }

        cin >> cmd;
    }

    cout << "bye" << endl;
}
