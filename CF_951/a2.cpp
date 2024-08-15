#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int X, Y;
        cin >> X >> Y;
        long long count = 1;
        while(X > 0 || Y > 0) {
            if (X%2 == Y%2) {
                count *= 2;
            } else {
                break;
            }
            X/= 2;
            Y/=2;
        }
        cout << count << "\n";
    }
    return 0;
}