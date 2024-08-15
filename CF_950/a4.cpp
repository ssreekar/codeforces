#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<int > arr(N);
        vector<vector<long long> > dp(N, vector<long long> (2, 1e10));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        dp[0][0] = 0;
        dp[1][0] = gcd(arr[0], arr[1]);
        dp[1][1] = 0;
        for (int i = 2; i < N; i++) {
            int gcdBack = gcd(arr[i], arr[i-1]);
            int gcdFar = gcd(arr[i], arr[i-2]);
            dp[i][0] = dp[i-1][0] <= gcdBack ? gcdBack : 1e10;
            long long option1 = dp[i-2][0] <= gcdFar ? gcdFar : 1e10;
            long long option2 = dp[i-1][1] <= gcdBack ? gcdBack : 1e10;
            dp[i][1] = min(option1, option2);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        if (dp[N-1][0] != 1e10 || dp[N-1][1] != 1e10 || dp[N-2][0] != 1e10) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}