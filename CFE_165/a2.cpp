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
        int nextPos = 0;
        long long total = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '0') {
                if (i != nextPos) {
                    total += i - nextPos + 1;
                }
                nextPos++;
            }
        }
        cout << total << '\n';
    }
    return 0;
}