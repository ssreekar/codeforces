#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int a,b,c;
        cin >> a >> b >> c;
        long long dis = 10000;
        long long val = 0;
        for (int i = 1; i <= 10; i++) {
            if (abs(a - i) + abs(b - i) + abs(c - i) < dis) {
                dis = abs(a - i) + abs(b - i) + abs(c - i);
                val = i;
            }
        }
        cout << dis << '\n';
    }
    return 0;
}