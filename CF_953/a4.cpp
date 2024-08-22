#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, C;
        cin >> N >> C;
        vector<long long> arr (N);
        int maxVal = 0;
        int maxIndex = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            long long value = arr[i];
            if (i == 0) {
                value += C;
            }
            if (value > maxVal) {
                maxVal = value;
                maxIndex = i;
            }
        }
        long long prefixSum = C;
        for (int i = 0; i < N; i++) {
            prefixSum += arr[i];
            long long total = i;
            if (i == maxIndex) {
                cout << 0 << " ";
                continue;
            }
            if (prefixSum >= maxVal) {
                cout << total << " ";
            } else {
                cout << total + 1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}