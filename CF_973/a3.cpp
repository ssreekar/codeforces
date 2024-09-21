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
        int response;
        bool forward = true;
        string binary = "0";
        cout << "? " << binary << endl;
        cin >> response;
        if (!response) {
            binary = "1";
        }
        while(binary.size() < N) {
            binary += "0";
            cout << "? " << binary << endl;
            cin >> response;
            if (response) {
                continue;
            } else {
                binary.back() = '1';
            }
            cout << "? " << binary << endl;
            cin >> response;
            if (response) {
                continue;
            } else {
                binary.pop_back();
                break;
            }
        }
        while(binary.size() < N) {
            binary.insert(binary.begin(), '0');
            cout << "? " << binary << endl;
            cin >> response;
            if (response) {
                continue;
            } else {
                binary[0] = '1';
            }
        }

        cout << "! " << binary << endl;

    }
    return 0;
}