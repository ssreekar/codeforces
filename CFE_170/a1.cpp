#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        string first, second;
        cin >> first >> second;
        int operations = 0;
        int firstSize = first.size();
        int secondSize = second.size();
        for (int i = 0; i < min(first.size(), second.size()); i++) {
            if (first[i] == second[i]) {
                operations++;
                firstSize--;
                secondSize--;
                if (i == 0) {
                    operations++;
                }
            } else {
                break;
            }
        }
        operations += firstSize + secondSize;
        cout << operations << '\n';
    }
    return 0;
}