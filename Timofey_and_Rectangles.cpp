#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> colours (N);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        colours[i] = (2 * (abs(x1) % 2)) + (1 + (abs(y1) % 2));
    }
    cout << "YES\n";
    for (int i = 0; i < colours.size(); i++) {
        cout << colours[i] << '\n';
    }
    return 0;
}