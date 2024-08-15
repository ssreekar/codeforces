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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int prev = arr[0];
        if (arr[0] != 1) {
            cout << "Alice\n";
            continue;
        }
        bool done = false;
        for (int i = 1; i < N; i++) {
            if (prev != arr[i]) {
                if (prev + 1 != arr[i]) {
                    if (prev % 2 == 0 ){
                        cout << "Alice\n";
                        done = true;
                        break;
                    } else {
                        cout << "Bob\n";
                        done = true;
                        break;
                    }
                }
            }
            prev = arr[i];
        }
        if (!done) {
            if (prev % 2 == 1) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        }
    }
    return 0;
}