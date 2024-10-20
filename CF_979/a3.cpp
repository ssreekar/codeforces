#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<char> arr (N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        bool prev = true;
        bool valid = false;
        for (int i = 0; i < N; i++) {
            if (arr[i] == '1' && prev) {
                valid = true;
            }
            prev = arr[i] == '1';
        }
        if (arr[N-1] == '1') {
            valid = true;
        }
        string val =  valid ? "YES" : "NO";
        cout << val << '\n';
    }
    return 0;
}