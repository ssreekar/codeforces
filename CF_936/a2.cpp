#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long MOD = 1e9 + 7;
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<long long> arr(N);
        vector<long long> prefix (N+1, 0);
        long long totalSum = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            totalSum += arr[i];
            totalSum %= MOD;
            prefix[i+1] = prefix[i] + arr[i];
        }
        long long minNumber = 0;
        long long bestSub = 0;
        for (int i = 1; i < N+1; i++) {
            minNumber = min(minNumber, prefix[i]);
            bestSub = max(bestSub, prefix[i] - minNumber);
        }
        if (bestSub > 0) {
            long long sumVal = 0;
            long long newValue = 1;
            long long power = 0;
            while(power < K) {
                sumVal += (newValue % MOD);
                sumVal %= MOD;
                power++;
                newValue *= 2;
                newValue %= MOD;
            }
            sumVal *= (bestSub % MOD);
            sumVal %= MOD;
            totalSum += sumVal;
            totalSum %= MOD;
        }
        totalSum %= MOD;
        if (totalSum < 0) {
            totalSum += MOD;
        }
        cout << totalSum << '\n';
        
    }
    return 0;
}