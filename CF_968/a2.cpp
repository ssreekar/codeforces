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
        sort(arr.begin(), arr.end());
        cout << arr[N/2] << '\n';
    }
    return 0;
}