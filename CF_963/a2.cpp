#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        long long biggestEven = 0;
        long long biggestOdd = 0;
        long long secondEven = 0;
        
        vector<long long> evens;
        vector<long long> odds;
        for (int i = 0; i < N; i++) {
            long long input;
            cin >> input;
            if (input % 2 == 0) {
                evens.push_back(input);
            } else {
                odds.push_back(input);
            }
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        long long total = 0;
        if (odds.size() ==0 || evens.size() == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long evenIndex = evens.size() - 1;
        long long oddIndex = odds.size()-1;
        bool down = true;
        long long oddVal = 0;
        while(evenIndex >= 0 && evenIndex < evens.size()) {
            if (down) {
                if (evens[evenIndex] > odds[oddIndex]) {
                    evenIndex--;
                } else {
                    down = false;
                    oddVal = odds[oddIndex];
                    evenIndex = 0;
                }
            } else {
                if (oddVal > evens[evenIndex]) {
                    oddVal += evens[evenIndex];
                    evenIndex++;
                } else {
                    break;
                }
            }
        }
        if (evenIndex < evens.size()) {
            cout << evens.size() + 1 << '\n';
        } else {
            cout << evens.size() << '\n';
        }

    }
    return 0;
}