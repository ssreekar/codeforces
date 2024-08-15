#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        unordered_map<int, int> count;
        bool done = false;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            count[arr[i]]++;
            if(count[arr[i]] >= K) {
                done = true;
            }
        }
        if (done) {
            cout << K-1 << '\n';
        } else {
            cout << N << '\n';
        }
    }
    return 0;
}