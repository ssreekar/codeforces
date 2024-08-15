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
        int N;
        cin >> N;
        vector<int> arrA(N);
        vector<int> arrB(N);

        for (int i = 0; i < N; i++) {
            cin >> arrA[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arrB[i];
        }
        int M;
        cin >> M;
        int lastVal = -1;
        unordered_map<long long, int, custom_hash> amounts;
        for (int i = 0; i < M; i++) {
            int value;
            cin >> value;
            amounts[value]++;
            if (i == M-1) {
                lastVal = value;
            }
            //cout << value << " " << amounts[value] << endl;
        }
        bool valid = false;
        bool done = false;
        for (int i = 0; i < N; i++) {
            if (arrA[i] != arrB[i]) {
                //cout << amounts.count(arrB[i]) << endl;
                auto it = amounts.find(arrB[i]);
                if (it != amounts.end() && it->second > 0) {
                    amounts[arrB[i]]--;
                    //cout << arrB[i] << " " << amounts[arrB[i]] << endl;
                } else {
                    done = true;
                    break;
                }
            }
            if (arrB[i] == lastVal) {
                valid = true;
            }
        }

        if (done || !valid) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}