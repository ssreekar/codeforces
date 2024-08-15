#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int x;
        cin >> x;
        vector<int> binary;
        while(x) {
            int val = x % 2 ? 1 : 0;
            binary.push_back(val);
            x /= 2;
        }
        reverse(binary.begin(), binary.end());
        while (true) {
            bool change = false;
            if (binary.size() >= 2 && binary[0] == 1 && binary[1] == 1) {
                binary[1] = -1;
                binary[0] = 0;
                binary.insert(binary.begin(), 1);
                change = true;
            }
            for (int i = 1; i < binary.size(); i++) {
                if (binary[i] != 0 && binary[i-1] != 0) {
                    if (binary[i-1] == 1 && binary[i] == 1) {
                        binary[i] = -1;
                        binary[i-1] = 0;
                        binary[i-2] = 1;
                        change = true;
                    } else if (binary[i-1] == -1 && binary[i] == 1){
                        binary[i] = -1;
                        binary[i-1] = 0;
                        change = true;
                    }
                }
            }
            if (!change){ 
                break;
            }
        }
        reverse(binary.begin(), binary.end());

        cout << binary.size() << endl;
        for (int i = 0; i < binary.size(); i++) {
            cout << binary[i] << " ";
        }
        cout << endl;

    }


    return 0;
}