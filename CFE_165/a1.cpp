#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        bool two = false;
        for (int i = 0; i < N; i++) {
            int bf = arr[i];
            if (arr[bf-1] == i+1) {
                two = true;
                break;
            }
        }
        if (two) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
    return 0;
}