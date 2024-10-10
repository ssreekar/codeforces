#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long K;
        cin >> K;
        long long lo = 1;
        long long hi = 2 * K;
        long long lowestValid = -1;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long sqrtM = sqrt(mid);
            //cout << lo << " " << hi << " " << mid << endl;
            long long newMid = mid - sqrtM;
            if (newMid < K) {
                lo = mid+1;
            } else if (newMid == K) {
                hi = mid-1; 
                lowestValid = mid;
            } else {
                hi = mid-1;
            }
        }
        cout << lowestValid << '\n';
    }
    return 0;
}