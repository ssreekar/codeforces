#include <iostream>
#include <vector>
#include <unordered_map>
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
        int N;
        cin >> N;
        vector<int> arr (N);
        long long sum = 0;
        unordered_map<long long, long long, custom_hash> counts;
        vector<pair<long long, long long> > secondPass;
        int maxVal = 0;
        int secondPassCount = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            sum += arr[i];
            counts[arr[i]]++;
            if (counts[arr[i]] >= 2) {
                if (arr[i] > maxVal) {
                    secondPass.push_back({maxVal, secondPassCount});
                    secondPassCount = 0;
                    maxVal = arr[i];
                }
                secondPassCount++;
            } else {
                secondPassCount++;
            }
            //cout << maxVal << " " << secondPassCount << endl;
            //sum += maxVal;
        }
        //cout << sum << endl;
        if (secondPassCount > 0) {
            secondPass.push_back({maxVal, secondPassCount});
        }
        long long passedAmount = 0;
        for (int i = secondPass.size(); i > 0; i--) {
            int index = i-1;
            long long value = secondPass[index].first;
            long long count = secondPass[index].second;
            cout << value << " " << count << endl;
            sum += value * count * passedAmount;
            sum += ((count + 1) * count * value) / (long long)2;
            passedAmount += count;
        }
        cout << sum << '\n';
    }
    return 0;
}