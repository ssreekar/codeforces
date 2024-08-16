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
        input[0] = '(';
        int index = 1;
        bool left = false;
        long long totalCount = 0;
        long long lastIndex = 0;
        while(index < input.size()) {
            if (input[index] == ')') {
                left = false;
                totalCount += index - lastIndex;
            } else if (input[index] == '_') {
                if (left) {
                    input[index] = ')';
                    totalCount+=1;
                } else {
                    input[index] = '(';
                    lastIndex = index;
                }
            } else {
                left = true;
            }
            index++;
        }
        cout << totalCount << '\n';
    }
    return 0;
}