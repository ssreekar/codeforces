#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cases = 0;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        ll N, C, K;
        cin >> N >> C >> K;
        vll arr (N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < N; i++) {
            if (C < arr[i]) {
                break;
            }
            ll subtract = min(K, (C - arr[i]));
            K -= subtract;
            C += arr[i] + subtract;
        }
        cout << C << '\n';
    }

    return 0;
}