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
        vector<long long> arrA(N);
        vector<long long> arrB(N+1);
        for (int i = 0; i < N; i++) {
            cin >> arrA[i];
        }
        for (int i = 0; i < N + 1; i++) {
            cin >> arrB[i];
        }
        long long lastVal = arrB.back();
        long long total = 0;
        long long bestAdd = 1e10;
        for (int i = 0; i < N; i++) {
            total += abs(arrA[i] - arrB[i]);
            if (lastVal >= arrA[i] && lastVal <= arrB[i]) {
                bestAdd = 1;
            } else if (lastVal <= arrA[i] && lastVal >= arrB[i]) {
                bestAdd = 1;
            }
            bestAdd = min(bestAdd, abs(arrA[i] - lastVal) + 1);
            bestAdd = min(bestAdd, abs(arrB[i] - lastVal) + 1);
        }
        total += bestAdd;
        cout << total << endl;
    }

    return 0;
}