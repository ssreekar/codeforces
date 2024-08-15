#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        if (N < 6) {
            if (N == 2) {
                cout << "1 1\n";
                cout << "1 2\n"; 
            } else if (N == 3) {
                cout << "2 1\n";
                cout << "2 3\n";
                cout << "3 1\n";
            } else if (N == 4) {
                cout << "1 1\n";
                cout << "1 3\n";
                cout << "4 3\n";
                cout << "4 4\n";
            } else if (N == 5) {
                cout << "1 1\n";
                cout << "1 3\n";
                cout << "1 4\n";
                cout << "2 1\n";
                cout << "5 5\n";
            }
        } else {
            int halfMark = ceil(double(N) / 2.0);
            for (int i = 0; i < N-3; i++) {
                cout << "1 " << i+1 << "\n"; 
            }
            cout << halfMark + 1 << " " << halfMark << "\n";
            cout << N << " " << halfMark << "\n";
            cout << N << " " << N << "\n";
            cout << "\n";
        }
    }
    return 0;
}