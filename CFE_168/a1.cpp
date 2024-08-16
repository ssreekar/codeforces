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
        bool done = false;
        for (int i = 1; i < input.size(); i++) {
            if (input[i] == input[i-1]) {
                done = true;
                char letter = input[i] == 'a' ? 'z' : 'a';
                input.insert(input.begin() + i, letter);
                break;
            }
        }
        if (!done) {
            char letter = input.back() == 'a' ? 'z' : 'a';
            input.push_back(letter);
        }
        cout << input << '\n';
    }
    return 0;
}