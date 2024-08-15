#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int x, y;
        cin >> x >> y;
        int yScreens = ceil(double(y)/2.0);
        int total = yScreens;
        int yMin = y / 2;
        x -= yMin * 7;
        yScreens -= yMin;
        x -= yScreens * 11;
        if (x > 0) {
            cout << total + ceil(double(x) / 15.0) <<  '\n';
        } else {
            cout << total << '\n';
        }

    }
    return 0;
}