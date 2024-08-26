#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    long long MOD = 1e9 + 7;
    for (int cases = 0; cases < T; cases++) {
        long long N, K; 
        cin >> N >> K;
        long long totalVal = N;
        for (int i = 0; i < K; i++) {
            long long R, C;
            cin >> R >> C;
            if (R == C) {
                totalVal--;
            } else {
                totalVal -= 2;
            }
        }
        vector<long long> dp (totalVal+10, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (long long i = 2; i <= totalVal; i++) {
            dp[i] = dp[i-1] % MOD;  
            dp[i] += ((dp[i-2] % MOD) * (((i - 1) * 2) % MOD)) % MOD;
            dp[i] %= MOD;
        }
        cout << dp[totalVal] << '\n';
    }
    return 0;
}