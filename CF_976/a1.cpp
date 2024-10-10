#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, K;
        cin >> N >> K;
        if (K == 1) {
            cout << N << '\n';
            continue;
        }
        long long current = 1;
        long long operations = 0;
        while(N > 0) {
            //cout << current << " " << N << endl;
            if (current <= N && current * K > N) {
                long long addition = N / current;
                N -= current * addition;
                operations += addition;
            } else if (current > N) {
                current /= K;
            } else {
                current *= K;
            }
        }
        cout << operations << '\n';
    }
    return 0;
}