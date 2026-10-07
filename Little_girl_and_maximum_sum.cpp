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
    ll N, Q;
    cin >> N >> Q;
    vll arr (N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vll diffArray (N+1, 0);
    for (int i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;
        diffArray[a-1]++;
        diffArray[b]--; 
    }
    vll finalArr (N, 0);
    finalArr[0] = diffArray[0];
    for (int i = 1; i < N; i++) {
        finalArr[i] = diffArray[i] + finalArr[i-1];
    }
    sort(finalArr.rbegin(), finalArr.rend());
    sort(arr.rbegin(), arr.rend());
    ll total = 0;
    for (int i = 0; i < N; i++) {
        total += finalArr[i] * arr[i];
    }
    cout << total << endl;

    return 0;
}