#include <cstdint>
#include <chrono>
#include <unordered_map>

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


// Custom Hash for pair of long long
struct custom_hash_pair {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM_X = chrono::steady_clock::now().time_since_epoch().count();
        static const uint64_t FIXED_RANDOM_Y = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((x.first + FIXED_RANDOM_X)^((x.second + FIXED_RANDOM_Y) >> 1));
    }
};

int main() {
    unordered_map<long long, int, custom_hash> value;
    unordered_map<pair<long long, long long>, long long, custom_hash_pair> pair_map;
}