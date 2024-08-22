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
        vector<int> counts (101, 0);
        int maxCount = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            counts[arr[i]]++;
            maxCount = max(maxCount, counts[arr[i]]);
        }
        cout << N - maxCount << '\n';
    }
    return 0;
}