#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;
const ll MODULO = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, K, D;
    cin >> N >> K >> D;
    //cout << N << " " << D << endl;
    if (N < D) {
        cout << "0" << endl;
        return 0;
    }
    vector<ll> OFunc(N+1, 0);
    OFunc[1] = 1;
    OFunc[0] = 1;
    for (int i = 2; i <= N; i++) {
        ll OFuncSum = 0;
        for (int j = i-1; j >= max(ll(0), i-K); j--) {
            OFuncSum += OFunc[j] % MODULO;
            OFuncSum %= MODULO;
        }
        OFunc[i] = OFuncSum;
        //cout << "O " << i << " " << OFunc[i] << endl; 
    }
    vll PFunc(N+1, 0);
    PFunc[D] = 1;
    for (int i = D+1; i <= N; i++) {
        ll PFuncSum = 0;
        for (int j = i-1; j >= max(ll(0), i-K); j--) {
            if (j <= i-D){
                PFuncSum += OFunc[j] % MODULO;
            } else {
                PFuncSum += PFunc[j] % MODULO;
            }
            PFuncSum %= MODULO;
        }
        PFunc[i] = PFuncSum;
        //cout << "P " << i << " " << PFunc[i] << endl; 
    }
    cout << PFunc[N] << endl;

    return 0;
}