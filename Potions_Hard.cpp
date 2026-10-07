#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

void insert(vll &tree, ll index, ll val) {
    ll N = tree.size() - 2;
    index = index + 1;
    while (index <= N) {
        cout << "Erm what the sigma" << endl;
        tree[index] += val;
        index += index & (-index);
    }
}

ll retrieve(vll &tree, ll index) {
    ll total = 0;
    index = index + 1;
    while(index > 0) {
        total += tree[index];
        index -= index & (-index);
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<ll,ll> > arr(N);
    vll fenwickTree (N+1, 0);
    ll total = 0;
    ll val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        arr[i] = {val, i};
        if (val >= 0) {
            total++;
            cout << val << " - Sealed" << endl;
            insert(fenwickTree, i, val);
        }
    }
    
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].first >= 0){continue;}
        ll amount = retrieve(fenwickTree, arr[i].second);
        if (amount >= arr[i].first) {
            cout << arr[i].first << " - Sealed" << endl;
            insert(fenwickTree, i, arr[i].first);
            total++;
        }
    }
    cout << total << endl;

}