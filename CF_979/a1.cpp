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
        int maxVal = 0;
        int minVal = 1001;
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            minVal = min(minVal, input);
            maxVal = max(maxVal, input);
        }
        //cout << maxVal << " " << minVal << endl;
        cout << (N-1) * (maxVal - minVal) << '\n';
    }
    return 0;
}