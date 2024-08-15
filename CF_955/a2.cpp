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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int x, y, k;
        cin >> x >> y >> k;
        unordered_map<long long, long long, custom_hash> visited;
        visited[x] = 0;
        long long counter = 0;
        while(true) {
            long long val = y - (x % y);
            //cout << "val " << val << endl;
            if (val > k) {
                cout << x + k << "\n";
                break;
            } else {
                x += val;
                k -= val;
                counter += val;
                while(x % y == 0) {
                    x /= y;
                }
                if (visited.find(x) == visited.end()) {
                    visited[x] = counter;
                } else {
                    long long diff = counter - visited[x];
                    k %= diff;
                    cout << x + k << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}