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
        string A, B;
        cin >> A >> B;
        string newB = B;
        for (int i = 0; i + 2< N; i++) {
            if (A[i] == '0' && A[i+2] == '0') {
                newB[i+1] = '1';
            }
        }
        //cout << endl;
        //cout << newB << endl;
        string newA = A;
        vector<int> prefixSum (N+1, 0);
        for (int i = 0; i + 2 < N; i++) {
            if (newB[i] == '1' && newB[i+2] == '1') {
                newA[i+1] = '1';
            }
        }
        //cout << endl;
        //cout << newA << endl;
        for (int i = 1; i <= N; i++) {
            prefixSum[i] = prefixSum[i-1];
            if (newA[i-1] == '1') {
                prefixSum[i]++;
            }
            //cout << prefixSum[i] << " ";
        }
        //cout << endl;

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            int L, R;
            cin >> L >> R;
            L--;
            R--;
            long long total = 0;
            if (A[L] == '1') {
                total++;
            }
            if (R - L == 0) {
                cout << total << '\n';
                continue;
            }
            if (A[R] == '1') {
                total++;
            }
            if (R - L == 1) {
                cout << total << '\n';
                continue;
            }
            if (R - L == 2) {
                if ((B[L] == '1' && B[L+2] == '1') || A[L+1] == '1') {
                    total++;
                }
                cout << total << '\n';
                continue;
            }

            if ((B[L] == '1' && newB[L+2] == '1') || A[L+1] == '1') {
                total++;
            }
            if ((B[R] == '1' && newB[R-2] == '1') || A[R-1] == '1') {
                total++;
            }
        
            total += prefixSum[R-1] - prefixSum[L+2];
            cout << total << '\n';
        }
    }
    return 0;
}