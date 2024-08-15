#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        if ((N-1) % (K-1) == 0) {
            cout << (N-1) / (K-1) << '\n';
        } else {
            cout << ((N-1) / (K-1)) + 1 << '\n';
        }
        
    }

    return 0;
}