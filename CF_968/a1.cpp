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
        string input;
        cin >> input;

        if (input[0] != input[N-1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}