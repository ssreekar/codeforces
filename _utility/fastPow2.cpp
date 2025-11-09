#include <bits/stdc++.h>

// Calculate 2^N
long long fastPow2(long long N) {
    long long curr = 1;
    long long pow2 = 2;
    while (N > 0) {
        if (N & 1) {
            curr *= pow2;
        }
        pow2 = pow2 << 1;
        N = N >> 1;
    }
    return curr;
}