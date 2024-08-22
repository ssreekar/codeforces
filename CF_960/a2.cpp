#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, X, Y;
        cin >> N >> X >> Y;
        X--;
        Y--;
        vector<int> arr (N);
        for (int i = Y; i <= X; i++) {
            arr[i] = 1;
        }
        int start = -1;
        for (int i = Y-1; i >= 0; i--) {
            arr[i] = start;
            start *= -1;
        }
        start = -1;
        for (int i = X+1; i < N; i++) {
            arr[i] = start;
            start *= -1;
        }
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}