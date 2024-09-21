#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <chrono>

using namespace std;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int findH(int R, int G) {
    int H = 1;
    while(G >= H) {
        G -= H;
        H++;
    }
    if (R >= H-G) {
        R -= (H - G);
        H++;
        G = 0;
    }
    while (R >= H) {
        R -= H;
        H++;
    }
    H--;
    return H;
}

long long MOD = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, G;
    cin >> R >> G;
    if (R < G) {
        swap(R, G);
    }
    int H = findH(R, G);
    vector<int> twoTable (H+1);
    twoTable[0] = 1;
    for (int i = 1; i < twoTable.size(); i++) {
        twoTable[i] = (twoTable[i-1] % MOD) * 2;
        twoTable[i] %= MOD;
    }
    
    int maxAmount = (H * (H + 1)) / 2;
    int dp[200010];
    int last = 0;
    dp[1] = 1;
    dp[0] = 1;
    for (int layer = 2; layer <= H; layer++) {
        for (int j = G; j >= 0; j--) {
            if (j > (layer * (layer + 1))/2) {
                dp[j] = 0;
            } else {
                dp[j] = dp[j] % MOD;
                if (j - layer >= 0) {
                    dp[j] += dp[j-layer] % MOD;
                    dp[j] %= MOD;
                }
            }
            if (layer == H) {
                if (maxAmount - j <= R) {
                    last += dp[j];
                    last %= MOD;
                } 
            }
        }
    }

    if (H == 1) {
        if (G == 0 || R == 0) {
            last = 1;
        } else {
            last = 2;
        }
    }
    cout << last << '\n';

    return 0;
}