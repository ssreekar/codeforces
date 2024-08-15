#include <iostream>
#include <algorithm>
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
        vector<long long> arr (N);
        vector<bool> valid (N, true);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int j = 0; j < N; j++) {
            if (arr[j] % arr[0] != 0) {
                valid[j] = false;
            }
        }
        for (int i = 1; i < N; i++) {
            if (valid[i] == false) {
                //cout << i << endl;
                valid[i] = true;
                for (int j = i+1; j < N; j++) {
                    if (valid[j] == false && arr[j] % arr[i] == 0) {
                        valid[j] = true;
                    }
                }
                break;
            }
        }
        bool done = false;
        for (int i = 0; i < N; i++) {
            if (!valid[i]) {
                done = true;
            } 
        }
        if (done) {
            cout << "No" << endl; 
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}