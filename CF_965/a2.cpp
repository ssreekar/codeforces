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
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[0] << '\n';
    }
    return 0;
}