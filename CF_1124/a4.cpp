#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

bool isValid(ll val) {
    static const vector<ll> validSet = {0, 3, 5, 6, 9, 10, 12, 15};
    return find(validSet.begin(), validSet.end(), val) != validSet.end();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, Q;
        cin >> N >> Q;
        vector<ll> arr (N);
        vector<pair<ll,ll> > updates(Q);

        ll totalValid = 0;
        for (auto &num: arr) {
            cin >> num;
            if (isValid(num)) {
                totalValid++;
            }
        } 
        cout << totalValid << " ";
        for (auto &pair: updates){
            cin >> pair.first;
            cin >> pair.second;
            if (isValid(arr[pair.first-1]) && !isValid(pair.second)) {
                totalValid--;
            }
            if (!isValid(arr[pair.first-1]) && isValid(pair.second)) {
                totalValid++;
            }
            cout << totalValid << " ";
            arr[pair.first-1] = pair.second;

        }
        cout << endl;
    }
    return 0;
}