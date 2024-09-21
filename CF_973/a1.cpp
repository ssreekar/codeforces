#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, x, y;
        cin >> N >> x >> y;
        int total = N / min(x, y);
        if (N % min(x, y) != 0) {
            total++;
        }
        cout << total << '\n';
    }
    return 0;
}