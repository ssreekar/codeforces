#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        vector<vector<int> > arrA (N, vector<int> (M));
        vector<vector<int> > arrB (N, vector<int> (M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char input;
                cin >> input;
                arrA[i][j] = input - '0';
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char input;
                cin >> input;
                arrB[i][j] = input - '0';
            }
        }

        bool valid = true;
        for (int i = 0; i < N; i++) {
            int rowSum = 0;
            for (int j = 0; j < M; j++) {
                int diff = arrB[i][j] - arrA[i][j];
                if (diff < 0) {
                    diff += 3;
                }
                rowSum += diff;
            }
            if (rowSum % 3 != 0) {
                valid = false;
                break;
            }
        }
        for (int i = 0; i < M; i++) {
            int colSum = 0;
            for (int j = 0; j < N; j++) {
                int diff = arrB[j][i] - arrA[j][i];
                if (diff < 0) {
                    diff += 3;
                }
                colSum += diff;
            }
            if (colSum % 3 != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}