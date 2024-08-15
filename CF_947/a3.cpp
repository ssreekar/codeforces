#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<long long> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        long long maxVal = -1;
        if (N == 2) {
            maxVal = min(arr[0], arr[1]);
        }
        for (int i = 2; i < N; i++) {
            long long val1 = max(arr[i-2], arr[i-1]);
            long long val2 = max(arr[i-1], arr[i]);
            long long val3 = max(arr[i], arr[i-2]);
            long long val4 = min(min(val1, val2), val3);
            maxVal = max(val4, maxVal);
        }
        cout << maxVal << endl;
    }
    return 0;
}