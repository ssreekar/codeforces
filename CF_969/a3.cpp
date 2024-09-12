#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, A, B;
        cin >> N >> A >> B;
        vector<long long> arr (N);
        long long gcd = std::gcd(A, B);
        long long minVal = 1e9;
        long long maxVal = -1;
        for (int i = 0; i < N; i++) {
            long long input;
            cin >> input;
            arr[i] = input % gcd;
            minVal = min(arr[i], minVal);
            maxVal = max(arr[i], maxVal);
        }
        sort(arr.begin(), arr.end());
        long long maxDiff = maxVal - minVal;
        for (int i = 1; i < N; i++) {
            long long option1 = gcd - abs(arr[i] - arr[i-1]);
            maxDiff = min(maxDiff, option1);
        }
        //cout << maxDiff << " " << maxDiff2 << endl;
        cout << maxDiff << '\n';
    }
    return 0;
}