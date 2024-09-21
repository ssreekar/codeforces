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
        if (K >= N-1) {
            cout << 1 << '\n';
        } else {
            cout << N << '\n';
        }
    }
    return 0;
}   