#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, D, K;
        cin >> N >> D >> K;
        vector<int> endAmount (N+1, 0);
        vector<int> startAmount (N+1, 0);
        for (int i = 0; i < K; i++) {
            int l, r;
            cin >> l >> r;
            startAmount[l]++;
            endAmount[r]++;
        }
        int curTotal = 0;
        int maxTotal = 0;
        int minTotal = 0;
        for (int i = 1; i <= D; i++) {
            curTotal += startAmount[i];
        }
        maxTotal = curTotal;
        minTotal = curTotal;
        int bestIndex = 1;
        int worstIndex = 1;
        for (int i = D+1; i <= N; i++) {
            curTotal += startAmount[i];
            curTotal -= endAmount[i-D];
            //cout << i << " " << curTotal << endl;
            if (curTotal > maxTotal) {
                maxTotal = curTotal;
                bestIndex = i - D +1;;
            } 
            if (curTotal < minTotal) {
                minTotal = curTotal;
                worstIndex = i - D + 1;
            }
        }
        cout << bestIndex << " " << worstIndex << '\n';
    }
    return 0;
}