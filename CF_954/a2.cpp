#include <iostream>
#include <vector>

using namespace std;

int getVal(int i, int j, vector<vector<int> > &matrix) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size()) {
        return 0;
    }
    return matrix[i][j];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        vector<vector<int> > matrix(N, vector<int> (M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int top = getVal(i - 1, j, matrix);
                int bot = getVal(i + 1, j, matrix);
                int left = getVal(i, j-1, matrix);
                int right = getVal(i, j+1, matrix);
                int val = matrix[i][j];
                if (val > max(top, bot) && val > max(left, right)) {
                    matrix[i][j] = max(max(top, bot), max(left, right));
                }
                cout << matrix[i][j] << " "; 
            }
            cout << '\n';
        }
    }
    return 0;
}