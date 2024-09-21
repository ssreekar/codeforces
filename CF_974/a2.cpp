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
        if (K >= N) {
            K = N;
        }
        int numsSummed = K;
        int oddSummed = 0;
        if (N % 2 == 1) {
            oddSummed = (numsSummed + 1) / 2;
        } else {
            oddSummed = numsSummed / 2;
        }
        if (oddSummed % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}