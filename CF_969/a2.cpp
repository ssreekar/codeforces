#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        vector<long long> arr (N);
        long long maxVal = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        for (int i = 0; i < M; i++) {
            char type;
            long long l, r;
            cin >> type >> l >> r;
            if (type == '+') {
                if (l <= maxVal && r >= maxVal) {
                    maxVal++;
                }
            } else {
                if (l <= maxVal && r >= maxVal) {
                    maxVal--;
                }
            }
            cout << maxVal << " ";
        }
        cout << '\n';

    }
    return 0;
}