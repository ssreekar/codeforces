#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<int> arr (N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        int count = 0;
        int prev = -1;
        bool done = false;
        for (int i = 0; i <= N; i++) {
            if (i == N || arr[i] != prev) {
                prev = arr[min(i, N-1)];
                if (count % 2 == 1) {
                    done = true;
                    break;
                }
                count = 1;

            } else {
                count++;
            }

        }
        if (done) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}