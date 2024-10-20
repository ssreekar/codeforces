#include <iostream>
#include <vector>

using namespace std;

void solve (int N, int K) {
    vector<vector<int> > C (N, vector<int> (N, 0));
    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) { // loop over k from 1 to n-1 (inclusive) 
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
        }
        for (int i = 0; i <= n; i++) {
            cout << C[n][i] << " ";
        }
        cout << endl;
    }
}

long long binPow(int base, int power) {
    long long MOD = 1e9 + 7;
    long long total = 1;
    long long curPower = base;
    while(power > 0) {
        if (power % 2 == 1) {
            total *= curPower;
            total %= MOD;
        }
        curPower *= curPower;
        curPower %= MOD;
        power /= 2;
    }
    return total % MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    vector<int> arrN (T);
    vector<int> arrK (T);
    for (int i = 0; i < T; i++) {
        cin >> arrN[i];
    }
    for (int i = 0; i < T; i++) {
        cin >> arrK[i];
    }
    for (int i = 0; i < T; i++) {
        int N = arrN[i];
        int K = arrK[i];
        if (N == K) {
            cout << 1  << '\n';
        } else {
            cout << binPow(2, K) << '\n';
        }
    }
    return 0;
}