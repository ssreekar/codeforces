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
        vector<int> arr (N);
        vector<int> counts (N, 0); 
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            counts[arr[i]]++;
        }
        int curBest = 0;
        bool first = false;
        for (int i = 0; i < N; i++) {
            if (counts[i] == 0) {
                break;
            } else {
                if (counts[i] == 1) {
                    if (!first) {
                        first = true;
                        curBest++;
                    } else {
                        break;
                    }
                } else {
                    curBest++;
                }
            }
        }
        cout << curBest << '\n';
        
    }
    return 0;
}