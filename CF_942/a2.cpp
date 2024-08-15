#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++){
        int N;
        cin >> N;
        int UVal = 0;
        for (int i = 0; i < N; i++) {
            char val;
            cin >> val;
            if (val == 'U') {
                UVal++;
            }
        }
        if (UVal % 2 == 0) {
            cout << "NO\n"; 
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}