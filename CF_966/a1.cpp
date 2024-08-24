#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        string input;
        cin >> input;
        if (input.size() <= 2) {
            cout << "NO\n";
            continue;
        }
        if (input[0] != '1' || input[1] != '0') {
            cout << "NO\n";
            continue;
        }
        if (input[2] == '0') {
            cout << "NO\n";
            continue;
        }
        if (input[2] == '1' && input.size() == 3) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}