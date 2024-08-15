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
        int index = 0;
        while (index + 1 < input.size()) {
            if (input[index] == '0' && input[index+1] == '0') {
                input.erase(input.begin() + index+1);
            } else {
                index++;
            }
        }
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        if (ones > zeros) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}