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
        vector<int> arr (N);
        long long total = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (i < N-2) {
                total += arr[i];
            }
        }
        total -= arr[N-2];
        total += arr[N-1];
        cout << total << '\n';
    }
    return 0;
}