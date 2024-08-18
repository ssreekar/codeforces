#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        int start = max(l, L);
        int end = min(r, R);
        if (end - start < 0) {
            cout << 1 << '\n';
        } else {
            int total = end - start;
            if (start != min(l, L)) {
                total++;
            } 
            if (end != max(r, R)) {
                total++;
            }
            cout << total << '\n';
        }

    }
    return 0;
}