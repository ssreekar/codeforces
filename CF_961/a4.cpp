#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N;
        cin >> N;
        vector<long long> arr(N);
        vector<long long> powerAmount (N, 0);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        bool impossible = false;
        for (int i = 0; i+1 < N; i++) {
            long long firstValue = arr[i];
            long long secondValue = arr[i+1];
            if (secondValue == 1 && firstValue != 1) {
                impossible = true;
                break;
            }
            if (secondValue == 1 && firstValue == 1) {
                continue;
            }
            if (firstValue <= secondValue) {
                long long powerLeft = powerAmount[i];
                while(firstValue <= secondValue && powerLeft > 0) {
                    firstValue = firstValue * firstValue;
                    powerLeft--;
                }
                if (firstValue > secondValue) {
                    powerAmount[i+1] = powerLeft + 1;
                }
            }
            else {
                long long powerTaken = 0;
                while(firstValue > secondValue) {
                    secondValue = secondValue * secondValue;
                    powerTaken++;
                }
                powerAmount[i+1] = powerAmount[i] + powerTaken;
            }
        }
        if (impossible) {
            cout << -1 << '\n';
            continue;
        }
        long long total = 0;
        for (int i = 0; i < N; i++) {
            total += powerAmount[i];
        }
        cout << total << '\n';
    }
    return 0;
}