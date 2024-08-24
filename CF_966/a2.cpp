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
        vector<bool> seats (N+2, false);
        bool valid = true;
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            if (i != 0) {
                if (seats[input+1] == false && seats[input-1] == false) {
                    valid = false;
                }
            }
            seats[input] = true;
        }
        string output = valid ? "YES" : "NO" ;
        cout << output << "\n";
    }
    return 0;
}