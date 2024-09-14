#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> arr (M);
        for (int i = 0; i < M; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            int input;
            cin >> input;
            int highestBelow = -1;
            int lowestAbove = N + 10;
            for (int j = 0; j < M; j++) {
                if (input > arr[j]) {
                    highestBelow = max(highestBelow, arr[j]);
                }
                if (input < arr[j]) {
                    lowestAbove = min(lowestAbove, arr[j]);
                }
            }
            if (highestBelow == -1) {
                cout << lowestAbove - 1 << '\n';
            } else if (lowestAbove == N + 10) {
                cout << N - highestBelow << '\n'; 
            } else {
                cout << (lowestAbove - highestBelow) / 2 << '\n';
            }
            
        }

    }
    return 0;
}