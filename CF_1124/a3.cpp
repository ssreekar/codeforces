#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<ll> arr (N);
        for (auto& num: arr) {
            cin >> num;
        } 
        ll total = 0;
        for (int i = K-1; i <= N-K; i++) {
            //cout << arr[i] << endl;
            total += arr[i];
        }
        for (int i = 0; i <= min(K-2, N-K); i++) {
            ll left = arr[i];
            ll right = arr[N-i-1];
            total += max(left, right);
        }
        //cout << "END" << endl;
        cout << total << endl;
    }
    return 0;
}