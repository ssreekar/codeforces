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
        vector<int> arr(N);
        int maxVal = 1e9 + 1;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (i > 0) {
                maxVal = min(maxVal, max(arr[i], arr[i-1]));
            }
        }
        cout << maxVal -1 << '\n';
    }
    return 0;
}