#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        if (N % 2 == 0) {
            cout << -1 << '\n';
        } else {
            for (int i = 1; i <= N; i+= 2) {
                cout << i << " ";
            }
            for (int i = N-1; i >= 1; i-=2) {
                cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}