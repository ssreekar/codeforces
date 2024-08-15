#include <iostream>
#include <vector>

using namespace std;

bool hasOpposite(bool row, int index, bool black, vector<vector<bool> > &isBlack) {
    if (row) {
        for (int i = 0; i < isBlack[index].size(); i++) {
            if (isBlack[index][i] != black) {
                return true;
            }
        } 
    } else {
        for (int i = 0; i < isBlack.size(); i++) {
            if (isBlack[i][index] != black) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        //cout << endl;
        int N, M;
        cin >> N >> M;
        vector<vector<bool> > isBlack(N, vector<bool> (M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char value;
                cin >> value;
                isBlack[i][j] = value == 'B';
            }
        }
        if (isBlack[0][0] == isBlack[N-1][M-1] || isBlack[N-1][0] == isBlack[0][M-1]) {
            //cout << isBlack[0][0] << " " <<  isBlack[N-1][M-1] << endl;
            cout << "YES\n";
            continue;
        }
    
    
        if (hasOpposite(true, 0, isBlack[0][0], isBlack) && hasOpposite(false, 0, isBlack[0][0], isBlack)) {
            cout << "YES\n";
            continue;
        }
    

        if (hasOpposite(true, 0, isBlack[0][M-1], isBlack) && hasOpposite(false, M-1, isBlack[0][M-1], isBlack)) {
            cout << "YES\n";
            continue;
        }

        if (hasOpposite(true, N-1, isBlack[N-1][M-1], isBlack) && hasOpposite(false, M-1, isBlack[N-1][M-1], isBlack)) {
            cout << "YES\n";
            continue;
        }

        if (hasOpposite(true, N-1, isBlack[N-1][0], isBlack) && hasOpposite(false, 0, isBlack[N-1][0], isBlack)) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}