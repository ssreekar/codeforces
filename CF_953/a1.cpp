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
        vector<int> arr (N);
        int maxVal = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (i != N-1) {
                maxVal = max(maxVal, arr[i]);
            }
        }
        cout << maxVal + arr[N-1] << '\n';
    }
    return 0;
}