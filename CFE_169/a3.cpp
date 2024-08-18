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
        long long N, K;
        cin >> N >> K;
        vector<long long> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long A = 0;
        long long B = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (N % 2 == i % 2) {
                B += arr[i];
            } else {
                A += arr[i];
            }
        }
        long long addable = 0;
        for (int i = 0; i+1 < arr.size(); i++) {
            if (N % 2 == i % 2) {
                addable += arr[i+1] - arr[i];
            }
        }

        addable = min(K, addable);
        cout << A - B - addable << "\n";

    }
    return 0;
}