#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, R;
        cin >> N >> R;
        int happy = 0;
        int extra = 0;
        for (int i = 0; i < N; i++) {
            int amount;
            cin >> amount;
            happy += (amount / 2) * 2;
            if (amount % 2 == 1) {
                extra++;
            }
            R -= (amount / 2);
        }
        happy += min(R, extra);
        extra -= min(R, extra);
        happy -= extra;
        cout << happy << '\n';

    }
    return 0;
}