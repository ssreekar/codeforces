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
        string input;
        cin >> input;
        string output = "";
        vector<int> counts (26);
        for (int i = 0; i < input.size(); i++) {
            counts[input[i] - 'a']++;
        }
        while(output.size() < N) {
            for (int j = 0; j < 26; j++) {
                if (counts[j] > 0) {
                    output += j + 'a';
                    counts[j]--;
                }
            }
        }

        cout << output << '\n';
        
    }
    return 0;
}