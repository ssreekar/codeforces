#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        int total = 0;
        int output = 0;
        for (int i = 0; i < N; i++ ){
            int input;
            cin >> input;
            if (input >= K) {
                total += input;
            } else if (input == 0 && total > 0) {
                output++;
                total--;
            }
        }
        cout << output << '\n';
    }
    return 0;
}