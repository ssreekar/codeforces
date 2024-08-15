#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        string pass;
        cin >> pass;
        bool done = false;
        char lastDig = '0';
        char lastChar = 'a';
        for (int i = 0; i < pass.size(); i++) {
            if (i > 0 && isdigit(pass[i]) && isalpha(pass[i-1])) {
                done = true;
            }
            if (isdigit(pass[i]) && pass[i] < lastDig) {
                done = true;
            } else {
                lastDig = pass[i];
            }
            if (isalpha(pass[i]) && pass[i] < lastChar) {
                done =true;
            } else {
                lastChar = pass[i];
            }
        }
        if (done) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}