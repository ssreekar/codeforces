#include <iostream>
#include <algorithm>
#include <vector>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<pair<long long, long long> > arr;
        unordered_map<long long, long long, custom_hash> counts;
        for (int i = 0; i < N; i++) {
            long long value;
            cin >> value;
            counts[value]++;
        }
        for (auto & [key, value]: counts) {
            arr.push_back({key, value});
        }
        sort(arr.begin(), arr.end());
        long long total = arr[0].second;
        int curK = 1;
        long long curSum = arr[0].second;
        ///cout << arr[0].first << " " << arr[0].second << " " << endl;
        for (int i = 1; i < arr.size(); i++) {
            //cout << arr[i].first << " " << arr[i].second << " " << endl;
            if (arr[i].first == arr[i-1].first+1) {
                curK++;
                curSum += arr[i].second;
                if (curK > K) {
                    curSum -= arr[i-K].second;
                    curK--;
                }
            } else {
                curK = 1;
                curSum = arr[i].second;
            }
            //cout << total << endl;
            total = max(total, curSum);
        }
        cout << total << '\n';
    }
    return 0;
}