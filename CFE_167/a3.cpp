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
        vector<int> arrA (N);
        vector<int> arrB (N);
        long long aVal = 0;
        long long bVal = 0;
        long long plusOne = 0;
        long long minueOne = 0;
        for (int i = 0; i < N; i++) {
            cin >> arrA[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arrB[i];
        }
        for (int i = 0; i < N; i++) {
            if (arrA[i] == arrB[i]) {
                if (arrA[i] == 1) {
                    plusOne++;
                } else if (arrA[i] == -1) {
                    minueOne++;
                }
                continue;
            }
            if (arrA[i] == 1) {
                aVal++;
            } 
            if (arrB[i] == 1) {
                bVal++;
            }
        }
        for (int i = 0; i < plusOne; i++) {
            if (aVal < bVal) {
                aVal++;
            } else {
                bVal++;
            }
        }
        for (int i = 0; i < minueOne; i++) {
            if (aVal > bVal) {
                aVal--;
            } else {
                bVal--;
            }
        }
        cout << min(aVal, bVal) << "\n";
    }
    return 0;
}