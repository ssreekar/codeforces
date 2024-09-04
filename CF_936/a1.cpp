#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int midIndex = (N-1)/2;
        int count = 0;
        while(midIndex < N && arr[midIndex] == arr[(N-1)/2]) {
            count ++;
            midIndex++;
        }
        cout << count << "\n";
    }
    return 0;
}