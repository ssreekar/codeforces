#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, K;
    cin >> N >> K;
    if (K <= ceil(double(N) / 2.0)) {
        cout << (K * 2) - 1 << '\n';
    } else {
        K -= ceil(double(N) / 2.0);
        cout << K * 2 << '\n';
    }
    return 0;
}