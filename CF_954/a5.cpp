#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        map<int, int> amounts;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            amounts[arr[i]]++;
        }
        unordered_map<int, vector<int>, custom_hash > kMod; 
        for (auto it = amounts.begin(); it != amounts.end(); ++it) {
            if (it->second % 2 == 1) {
                int kModVal = it->first % K;
                kMod[kModVal].push_back(it->first);
            }
        }

        //cout << "SKIBIDI" << endl;
        long long total = 0;
        int evenCount = 0;
        for (auto it = kMod.begin(); it != kMod.end(); ++it) {
            if (it->second.size() % 2 == 0) {
                for (int i = 0; i < it->second.size(); i+=2) {
                    total += (it->second[i+1] - it->second[i]) / K;
                }
            } else {
                evenCount ++;
                vector<long long> forward (it->second.size(), 0);
                vector<long long> backward (it->second.size(), 0);
                long long current = 0;
                for (int i = 1; i < it->second.size(); i+=2) {
                    current += (it->second[i] - it->second[i-1]) / K;
                    forward[i] = current;
                }
                current = 0;
                for (int i = int(it->second.size())-2; i >= 0; i-=2) {
                    current += (it->second[i+1] - it->second[i]) / K;
                    backward[i] = current;
                }
                long long minVal = 1e18;
                for (int i = 0; i < it->second.size(); i++) {
                    if (i % 2 == 0) {
                        long long curTotal = 0;
                        if (i > 0) {
                            curTotal += forward[i-1];
                        }
                        if (i+1 < it->second.size()) {
                            curTotal += backward[i+1];
                        }
                        minVal = min(minVal, curTotal);
                    }
                }
                total += minVal;
            }
        }
        if (evenCount > 1) {
            cout << -1 << '\n';
        } else {
            cout << total << '\n';
        }

    }
    return 0;
}