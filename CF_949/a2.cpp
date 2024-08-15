#include <iostream>
#include <vector>

using namespace std;

// Constant Log Method 
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}


long long bitwiseOrRange(long long a, long long b) {
    long long lowestBit = max(log2_floor(a), log2_floor(b));
    //cout << lowestBit << endl;
    long long finalVal = 0;
    bool ones = false;
    for (int i = lowestBit; i >= 0; i--) {
        if (ones) {
            finalVal = finalVal | (1 << i);
            //cout << (i << i) << endl;
        } else {
            bool aSet = a & (1 << i);
            bool bSet = b & (1 << i);
            if (aSet && bSet) {
                finalVal = finalVal | (1 << i);
                //cout << finalVal << endl;
            } else if (!aSet && bSet) {
                finalVal = finalVal | (1 << i);
                //cout << finalVal << endl;
                ones = true;
            }
        }
    }
    return finalVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            cout << 0 << endl;
            continue;
        }
        cout << bitwiseOrRange(max(n - m, (long long)1), n + m) << endl;
    }
    return 0;
}