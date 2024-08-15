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
        long long N, K;
        cin >> N >> K;
        vector<long long> arrA (N);
        vector<long long> arrB (N);
        long long lastZero = -1;
        long long lastOne = -1;
        for (int i = 0; i < N; i++) {
            cin >> arrA[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arrB[i];
            if (arrB[i] == 0) {
                lastZero = i;
            } else {
                lastOne = i;
            }
        }
        sort(arrA.begin(), arrA.end());
        long long middleIndex = (N / 2) - 1;
        long long maxVal = 0;
        if (lastOne > -1) {
            long long curVal = arrA[lastOne] + K;
            if (lastOne > middleIndex) {
                curVal += arrA[middleIndex];
            } else {
                curVal += arrA[middleIndex+1];
            }
            maxVal = max(maxVal, curVal);
        }
        if (lastZero > -1) {
            long long curVal = arrA[lastZero];
            long long startIndex = middleIndex;
            if (lastZero <= middleIndex) {  
                startIndex = middleIndex + 1;
            }
            long long KLeft = K;
            int indexToGet = startIndex+1;
            long long totalAdds = 1;
            long long curMedian = arrA[startIndex];
            for (int i = startIndex; i >= N; i--) {
                if (arrB[i] == 0) {
                    continue;
                }
                long long nextNum = arrA[indexToGet];
                long long currentAmount = arrA[i];
                if (KLeft >= totalAdds * (nextNum - currentAmount)) {
                    KLeft -= totalAdds * (nextNum - currentAmount);
                    curMedian = nextNum;
                    totalAdds++;
                } else {
                    long long amountCanAdd = KLeft / totalAdds;
                    long long median = max(currentAmount + amountCanAdd, curMedian);
                    KLeft = 0;
                    break;
                }
            }
            if(KLeft > 0) {
                long long totalAdds = N - startIndex;
                long long amountCanAdd = KLeft / totalAdds;
                curVal += arrA[N-1] + amountCanAdd;
                KLeft = 0;
            }
            maxVal = max(maxVal, curVal);
        }
        cout << maxVal << '\n';
    }
    return 0;
}