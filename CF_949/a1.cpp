#include <iostream>
#include <vector>

using namespace std;

// Constant Log Method 
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int l, r;
        cin >> l >> r;
        cout << log2_floor(r) << endl;
    }
    return 0;
}