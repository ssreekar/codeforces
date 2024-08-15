#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

long long checkLCM(vector<long long> &arr, long long lcm) {
    long long totalSize = 0;
    long long currLCM = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (lcm % arr[i] == 0) {
            totalSize++;
            currLCM = std::lcm(currLCM, arr[i]);
        }
    }
    if (currLCM != lcm) {
        return 0;
    }
    return totalSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N;
        cin >> N;
        vector<long long> arr (N);
        unordered_set<long long> present;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            present.insert(arr[i]);
        }
        long long bestValue = 0;
        sort(arr.begin(), arr.end());
        long long value = arr.back();
        if (checkLCM(arr, value) != N) {
            cout << N << endl;
            continue;
        }
        //cout << sqrt(value) + 2 << endl;
        for (int i = 1; i <= (long long)(sqrt(value) + 2); i++) {
            if (value % i == 0) {
                long long divisorOne = value / i;
                long long divisorTwo = i;
                //cout << divisorOne << " " << divisorTwo << endl;
                if (present.find(divisorOne) == present.end()) {
                    bestValue = max(bestValue, checkLCM(arr, divisorOne));
                }
                if (present.find(divisorTwo) == present.end()) {
                    bestValue = max(bestValue, checkLCM(arr, divisorTwo));
                }
                //cout << i << " : " << bestValue << endl;
            }
            //cout << "?" << endl;
        }
        cout << bestValue << endl;
    }

    return 0;
}