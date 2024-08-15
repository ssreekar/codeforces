#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<long long> arr (N);
        vector<long long> prefix (N+1, 0);
        vector<vector<long long> > dp (N+1, vector<long long> (K+1, -1));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            prefix[i+1] = prefix[i] + arr[i];
        }
        for (int i = 0; i < K; i++) {
            dp[N][i] = 0;
        }
        for (int j = 0; j < N; j++) {
            dp[j][0] = 0;
        }

        long long totalMax = 0;
        for (int i = N-1; i >= 0; i--) {
            //cout << "I: " << i << " "; 
            for (int j = 1; j <= K; j++) {
                long long maxVal = max(dp[i][j-1], dp[i+1][j]);
                for (int k = 1; k <= j; k++){
                    int startIndex = i;
                    int endIndex = i + k - 1;
                    if (endIndex < N) {
                        long long rangeAmount = prefix[endIndex+1] - prefix[startIndex];
                        long long leftVal = startIndex-1 >= 0 ? arr[startIndex-1] : 1e10;
                        long long rightVal = endIndex+1 < N ? arr[endIndex+1] : 1e10;
                        long long changeVal = min(leftVal, rightVal);
                        long long indicies = endIndex - startIndex + 1;
                        long long amountSaved = rangeAmount - (changeVal * indicies);
                        long long newVal = amountSaved + dp[endIndex+1][j-k];
                        maxVal = max(maxVal, newVal);
                    }
                }
                dp[i][j] = maxVal;
                totalMax = max(dp[i][j], totalMax);
                //cout << dp[i][j] << " ";
            }
            //cout << '\n';
        }
        cout << prefix[N] - totalMax << '\n';
    }
    return 0;
}