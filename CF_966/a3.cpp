#include <iostream>
#include <vector>
#include <string>
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
        vector<long long> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        } 
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            string input;
            cin >> input;
            if (input.size() != N) {
                cout << "NO\n";
                continue;
            }
            vector<long long> letterMapping (26, 1e18);
            unordered_map<long long, int, custom_hash> numberMapping;
            bool valid = true;
            for (int j = 0; j < N; j++) {
                int letter = input[j] - 'a';
                if (letterMapping[letter] == 1e18) {
                    letterMapping[letter] = arr[j];
                } else {
                    if (letterMapping[letter] != arr[j]) {
                        valid = false;
                        break;
                    }
                }
                auto it = numberMapping.find(arr[j]);
                if ( it == numberMapping.end()) {
                    numberMapping[arr[j]] = letter;
                } else {
                    if (it->second != letter) {
                        valid = false;
                        break;
                    }
                }
            }
            numberMapping.clear();
            string output = valid ? "YES" : "NO";
            cout << output << "\n";
            
        }

    }
    return 0;
}