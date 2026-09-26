// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

template <typename Compare>
class heap {
private:
    vector<lli> heap_;
    unordered_map<lli, lli> ind;
    Compare comp;

    void sieve_up(lli x) {
        while (x != 0LL and not comp(heap_[(x - 1LL) / 2LL], heap_[x])) {
            swap(heap_[(x - 1LL) / 2LL], heap_[x]);
            swap(ind[heap_[(x - 1LL) / 2LL]], ind[heap_[x]]);
            x = (x - 1LL) / 2LL;
        }
    }

    void sieve_down(lli x) {
        lli x1 = 2LL * x + 1LL,
            x2 = 2LL * x + 2LL;
        while (x1 < (lli)heap_.size()) {
            if (x2 < (lli)heap_.size()) { // 2 children
                if (not comp(heap_[x], heap_[x1]) or not comp(heap_[x], heap_[x2])) {
                    if (comp(heap_[x1], heap_[x2])) {
                        swap(heap_[x], heap_[x1]);
                        swap(ind[heap_[x]], ind[heap_[x1]]);
                        x = x1;
                        x1 = 2LL * x + 1LL;
                        x2 = 2LL * x + 2LL;
                    } else { // comp(heap_[x2], heap_[x1])
                        swap(heap_[x], heap_[x2]);
                        swap(ind[heap_[x]], ind[heap_[x2]]);
                        x = x2;
                        x1 = 2LL * x + 1LL;
                        x2 = 2LL * x + 2LL;
                    }
                } else // comp(heap_[x], heap_[x1]) and comp(heap_[x], heap_[x2])
                    break;
            } else { // 1 child
                if (not comp(heap_[x], heap_[x1])) {
                    swap(heap_[x], heap_[x1]);
                    swap(ind[heap_[x]], ind[heap_[x1]]);
                }
                break;
            }
        }
    }

public:
    void push(lli k) {
        heap_.pb(k);
        ind[k] = (lli)heap_.size() - 1LL;

        lli x = (lli)heap_.size() - 1LL;
        sieve_up(x);
    }

    lli top() {
        return heap_.front();
    }

    void pop() {
        lli old_root = heap_.front();
        heap_.front() = heap_.back();
        heap_.pop_back();
        ind[heap_.front()] = 0LL;
        ind.erase(old_root);

        lli x = 0LL;
        sieve_down(x);
    }

    // лишь написав ненужный код, мы понимаем его ненужность...
    void erase(lli k) {
        lli x = ind[k];
        if (x == (lli)heap_.size() - 1LL) {
            heap_.pop_back();
            ind.erase(k);
            return;
        }

        heap_[x] = heap_.back();
        heap_.pop_back();
        ind[heap_[x]] = x;
        ind.erase(k);

        if (comp(heap_[x], k))
            sieve_up(x);
        else // comp(k, heap_[x])
            sieve_down(x);
    }

    lli size() {
        return (lli)heap_.size();
    }

    bool empty() {
        return heap_.empty();
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

    heap<greater<lli>> l;
    heap<less<lli>> r;
    lli k;
    while (n--) {
        cin >> k;

        if (l.empty())
            l.push(k);
        else { // not l.empty()
            if (k < l.top())
                l.push(k);
            else // l.top() < k
                r.push(k);
        }

        while (l.size() - r.size() > 1LL) {
            r.push(l.top());
            l.pop();
        }
        while (l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        }

        cout << l.top() << ' ';
    }
    cout << '\n';
}
