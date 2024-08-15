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
        vector<int> values (4, 0);
        for (int i = 0; i < input.size(); i++) {
            if (input[i] != '?') {
                values[input[i] - 'A']++;
            }
        }
        int total = 0;
        for (int i = 0; i < values.size(); i++) {
            total += min(N, values[i]);
        }
        cout << total << '\n';
    }
    return 0;
}