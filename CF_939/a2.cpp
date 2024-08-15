#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        vector<int> amounts((2 * N) + 1, 0);
        int doubles = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            amounts[arr[i]]++;
            if (amounts[arr[i]] == 2) {
                doubles++;
            }
        }
        cout << doubles << endl;

    }
    return 0;
}