#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T;
    cin >> T;
    for (long long cases = 0; cases < T; cases++) {
        long long N, X;
        cin >> N >> X;
        vector<long long> arr (N);
        for (long long i = 0; i < N; i++) {
            cin >> arr[i];
        } 
        arr.push_back(0);
        sort(arr.rbegin(), arr.rend());
        long long used = 0;
        long long extra = 0;
        long long curSize = arr[0];
        long long curAmount = 1;
        long long startSize = arr[0];
        for (long long i = 1; i < arr.size(); i++) {
            //cout << curSize << " " << curAmount << " " << used << " " << extra << endl;
            if (arr[i] == curSize) {
                curAmount++;
            } else {
                if (used < startSize - arr[i]) {
                    long long diff = startSize - arr[i] - used;
                    used += diff;
                    extra += diff * X;
                }
                //cout << used << " " << extra << endl;
                long long needed = (curSize - arr[i]) * curAmount;
                long long minAmount = min(extra, needed);
                needed -= minAmount;
                extra -= minAmount;
                //cout << used << " " << extra <<" " << needed << endl;
                if (needed > 0) {
                    long long addedAmount = needed / X;
                    if (needed % X != 0) {
                        addedAmount++;
                        extra = needed % X;
                    }
                    used += addedAmount;
                }
                curSize = arr[i];
                curAmount++;
            }
        }
        cout << used << '\n';
    }
    return 0;
}