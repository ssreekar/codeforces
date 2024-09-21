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
        vector<long long> arr (N);
        long long maxIndex = 0;
        long long maxAmount = 0;
        long long total = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (maxAmount < arr[i]) {
                maxIndex = i;
                maxAmount = arr[i];
            }
            total += arr[i];
        }
        sort(arr.begin(), arr.end());  
        if (N <= 2) {
            cout << "-1\n";
            continue;
        }
        long long currentAdd = 0;
        long long unhappy = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] * 2 * N < total) {
                unhappy++;
            } else if (unhappy * 2 <= N) {
                long long amount = arr[i] * 2 * N;
                //cout << total << " " << amount << endl;
                currentAdd += (amount+1) - total;
                total += (amount+1) - total;
                unhappy++;
            }
            if (unhappy * 2 > N) {
                break;
            }
        }
        cout << currentAdd << '\n';


    }
    return 0;
}