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
        vector<char> letters;
        vector<bool> visited(26, false);
        for (int i = 0; i < input.size(); i++) {
            if (visited[input[i] - 'a'] == false) {
                visited[input[i] - 'a'] = true;
                letters.push_back(input[i]);
            }
        }
        sort(letters.begin(), letters.end());
        for (int i = 0; i < input.size(); i++) {
            char letter = input[i];
            int index = 0;
            for (int j = 0; j < letters.size(); j++) {
                if (letters[j] == letter) {
                    index = letters.size() - 1 - j;
                }
            }
            input[i] = letters[index];
        }
        cout << input << '\n';
    }
    return 0;
}