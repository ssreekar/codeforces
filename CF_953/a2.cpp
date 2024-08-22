#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, A, B;
        cin >> N >> A >> B;
        long long diff = B - A;
        long long total = 0;
        if (diff <= 0) {
            total += N * A;
        } else if (diff > N) {
            total = ((B + (B - N + 1)) * N) / (long long)2;
        } else {
            total = N * A;
            total += ((diff + 1) * (diff)) / (long long)2;
        }
        cout << total << '\n';
    }
    return 0;
}