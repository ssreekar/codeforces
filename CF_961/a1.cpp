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
        int diagonals = 1;
        if (K == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (K <= N) {
            cout << diagonals << '\n';
            continue;
        }
        K -= N;
        int subAmount = N - 1;
        while(K >= subAmount && subAmount > 0) {
            K -= subAmount;
            diagonals++;
            if (K >= subAmount) {
                K -= subAmount;
                diagonals++;
            } else {
                break;
            }
            subAmount--;
        }
        if (K > 0) {
            diagonals++;
        }
        cout << diagonals << "\n";
    }
    return 0;
}