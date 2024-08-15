#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        int total = 0;
        long long totalLCM = 1;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            totalLCM = lcm(totalLCM, arr[i]);
        }
        for (int i = 0; i < N; i++) {
            total += totalLCM / arr[i];
        }
        //cout << "total" << total << '\n';
        if (total >= totalLCM) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < N; i++) {
                cout << totalLCM / arr[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}