#include <iostream>
#include <vector>

using namespace std;

// Constant Log Method 
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        if (N == 1) {
            cout << K << '\n';
        } else {
            int highestBit = log2_floor(K);
            int newK = (1 << highestBit) - 1;
            cout << newK << " " << K - newK << " ";
            for (int i = 0; i + 2< N; i++) {
                cout << 0 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}