// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

class heap {
private:
    vector<lli> heap_;

public:
    void insert(lli k) {
        heap_.pb(k);
        lli x = (lli)heap_.size() - 1LL;
        while (x != 0LL and heap_[(x - 1LL) / 2LL] < heap_[x]) {
            swap(heap_[(x - 1LL) / 2LL], heap_[x]);
            x = (x - 1LL) / 2LL;
        }
    }

    lli extract() {
        lli root = heap_.front();
        heap_.front() = heap_.back();
        heap_.pop_back();

        lli x = 0LL,
            x1 = 2LL * x + 1LL,
            x2 = 2LL * x + 2LL;
        while (x1 < (lli)heap_.size()) {
            if (x2 < (lli)heap_.size()) { // 2 children
                if (heap_[x] < heap_[x1] or heap_[x] < heap_[x2]) {
                    if (heap_[x1] > heap_[x2]) {
                        swap(heap_[x], heap_[x1]);
                        x = x1;
                        x1 = 2LL * x + 1LL;
                        x2 = 2LL * x + 2LL;
                    } else {
                        swap(heap_[x], heap_[x2]);
                        x = x2;
                        x1 = 2LL * x + 1LL;
                        x2 = 2LL * x + 2LL;
                    }
                } else // heap_[x] >= heap_[x1] and heap_[x] >= heap_[x2]
                    break;
            } else { // 1 child
                if (heap_[x] < heap_[x1])
                    swap(heap_[x], heap_[x1]);
                break;
            }
        }

        return root;
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;

    heap heap_; // ура!
    lli cmd,
        k;
    while (n--) {
        cin >> cmd;
        if (cmd == 0LL) {
            cin >> k;
            heap_.insert(k);
        } else // cmd == 1LL
            cout << heap_.extract() << '\n';
    }
}
