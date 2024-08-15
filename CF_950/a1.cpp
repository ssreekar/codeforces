#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int n, m;
        cin >> n >> m;
        string input;
        cin >> input;
        long long total = 7 * m;
        unordered_map<char, int> amounts;
        for (int i = 0; i < n; i++){
            amounts[input[i]]++;
            if (amounts[input[i]] <= m) {
                total--;
            }
        }
        cout << total << endl;
    }
    return 0;
}