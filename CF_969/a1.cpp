#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int l, r;
        cin >> l >> r;
        int total = (r - l+ 1) / 4;
        if ((r - l +1) % 4 == 3 && l % 2 == 1) {
            total++;
        }
        cout << total << '\n';

    }
    return 0;
}