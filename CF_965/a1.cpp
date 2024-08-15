#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int X, Y, K;
        cin >> X >> Y >> K;
        int start = 0;
        if (K % 2 == 1) {
            start = 1;
            cout << X << " " << Y << "\n";
        }
        int count = 0;
        for (int i = start; i < K; i++) {
            if (i % 2 == start % 2) {
                count++;
            }
            if (i % 2 == 0) {
                cout << X - count << " " << Y << '\n';
            } else {
                cout << X + count << " " << Y << '\n';
            }
        }
    }
    return 0;
}