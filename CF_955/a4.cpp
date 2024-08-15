#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int> > matrix (N, vector<int> (M));
        vector<vector<char> > type (N, vector<char> (M));
        vector<vector<long long> > dpSnow (N+1, vector<long long> (M+1, 0));
        vector<vector<long long> > dpNo (N+1, vector<long long> (M+1, 0));
        long long totalSnow = 0;
        long long totalNo = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> type[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (type[i][j] == '0') {
                    dpNo[i+1][j+1] = dpNo[i+1][j] + dpNo[i][j+1] - dpNo[i][j] + 1;
                    dpSnow[i+1][j+1] = dpSnow[i+1][j] + dpSnow[i][j+1] - dpSnow[i][j];
                    totalNo += matrix[i][j];
                } else {
                    dpNo[i+1][j+1] = dpNo[i+1][j] + dpNo[i][j+1] - dpNo[i][j];
                    dpSnow[i+1][j+1] = dpSnow[i+1][j] + dpSnow[i][j+1] - dpSnow[i][j] + 1;
                    totalSnow += matrix[i][j];
                }
            }
        }
        //cout << "Here" << endl;

        long long totalDiff = abs(totalSnow - totalNo);
        vector<long long> diffs;
        //cout << "Here Skibidi" << endl;

        for (int i = K-1; i < N; i++) {
            for (int j = K-1; j < M; j++) {
                int hiI = i;
                int loI = i - K;
                int hiJ = j;
                int loJ = j - K;
                long long snow = dpSnow[hiI+1][hiJ+1] - dpSnow[hiI+1][loJ+1] - dpSnow[loI+1][hiJ+1] + dpSnow[loI+1][loJ+1];
                long long no = dpNo[hiI+1][hiJ+1] - dpNo[hiI+1][loJ+1] - dpNo[loI+1][hiJ+1] + dpNo[loI+1][loJ+1];
                long long diff = abs(snow - no);
                diffs.push_back(diff);
            }
        }
        long long gcdAll = 0;
        for (int i = 0; i < diffs.size(); i++) {
            //cout << diffs[i] << endl;
            gcdAll = std::gcd(gcdAll, diffs[i]);
        }
        //cout << "GCD " << gcdAll << endl; 
        //cout << "Total Diff " << totalDiff << endl;
        if (gcdAll == 0) {
            if (totalDiff == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            if (totalDiff % gcdAll == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }

    }
    return 0;
}