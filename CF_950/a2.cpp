#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, F, K;
        cin >> N >> F >> K;
        int favVal = -1;
        vector<pair<int, int> > arr(N);
        for (int i = 0; i < N; i++) {
            int value;
            cin >> value;
            arr[i] = {value, i};
            if (i == F-1) {
                favVal = value;
            }
        }
        sort(arr.rbegin(), arr.rend());
        int loIndex = -1;
        int hiIndex = -1;
        for (int i = 0; i < N; i++) {
            if (arr[i].first == favVal) {
                if (loIndex == -1) {
                    loIndex = i;
                }
                hiIndex = i;
            }
        }
        //cout << loIndex << " " << hiIndex << endl;
        if (hiIndex <= K-1) {
            cout << "YES" << endl;
        } else if (loIndex > K-1) {
            cout << "NO" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    }
    return 0;
}