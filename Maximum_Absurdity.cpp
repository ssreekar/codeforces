#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<long long> arr(N);
    vector<long long> dp (N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i+1] = dp[i] + arr[i];
    }

    long long bestVal = 0;
    long long bestIndex = 0;
    for (int i = 0; i + K - 1 < N; i++) {
        long long curTotal = dp[i + K] - dp[i];
        if (curTotal > bestVal) {
            bestVal = curTotal;
            bestIndex = i;
        }
    }

    for (int i = bestIndex; i < N; i++) {
        dp[i+1] = dp[i];
        if (i > bestIndex + K - 1)
    }

    return 0;
}