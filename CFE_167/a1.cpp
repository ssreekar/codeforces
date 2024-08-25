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
        if (Y >= -1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}