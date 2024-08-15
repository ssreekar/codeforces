#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T;cases++) {
        int X;
        cin >> X;
        int maxVal = 1;
        int maxGcd = 1;
        for (int i = 1; i < X; i++) {
            if (maxGcd < gcd(X, i) + i) {
                maxVal = i;
                maxGcd = gcd(X, i) + i;
            }
        }
        cout << maxVal << '\n';
    }
    return 0;
}