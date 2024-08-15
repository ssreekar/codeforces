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
        vector<int> arrA(N);
        vector<int> arrB(N);
        for (int i = 0; i < N; i++) {
            cin >> arrA[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arrB[i];
        }
        int aIndex = 0;
        int bIndex = 0;
        int totalAdded = 0;
        while(bIndex < N) {
            if (arrA[aIndex] <= arrB[bIndex]) {
                aIndex++;
                bIndex++;
            } else {
                totalAdded++;
                bIndex++;
            }
        }
        cout << totalAdded << '\n';
    }
    return 0;
}