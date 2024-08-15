#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if (x0 <= y0 && x1 >= y1) {
            cout << "No\n"; 
        } else if (y0 <= x0 && y1 >= x1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}