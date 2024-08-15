#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        int M;
        cin >> M;
        if (M > N) {
            cout << "No" << endl;
        } else if (N % 2 != M % 2) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}