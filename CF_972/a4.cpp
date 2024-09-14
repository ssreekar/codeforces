#include <iostream>
#include <vector>
#include <utility>
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

long long specialFunc(int amount, int index, int end) {
    long long total = 0;
    total += end * 100000000;
    total += index * 10000;
    total += amount;
    return total;
}


long long recurse(int amount, int index, int end, vector<vector<pair<int, int> > > &data, map<vector<int>, long long> &memo) {
    vector<int> specialVal = {amount,index,end};
    auto it = memo.find(specialVal);
    if (it != memo.end()) {
        return memo[specialVal];
    }
    int N = data.size();
    if (index == N) {
        return amount - (end * 2);
    }
    //cout << "start " << amount << index << end << endl;
    long long val1 = recurse(amount, index+1, end, data, memo);
    int x = data[index][end].first;
    int newEnd = data[index][end].second;
    long long val2 = recurse(amount+x, index+1, newEnd, data, memo);
    memo[specialVal] = max(val1, val2);
    //cout << amount << " " << index << " " << end << " " << max(val1, val2) << endl;
    return max(val1, val2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        vector<string> arr (N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        vector<char> name = {'n', 'a', 'r', 'e', 'k'};
        vector<vector<pair<int, int> > > data (N, vector<pair<int, int> > (5));
        for (int i = 0; i < N; i++) {
            string value = arr[i];
            for (int j = 0; j < 5; j++) {
                char lookingFor = name[j];
                int lookingIndex = j;
                int total = 0;
                for (int z = 0; z < M; z++) {
                    char currentLetter = arr[i][z];
                    if (currentLetter == lookingFor) {
                        lookingIndex++;
                        lookingFor = name[lookingIndex%5];
                        total++;
                    } else if (currentLetter == 'n' || currentLetter == 'a' || currentLetter =='r' || currentLetter == 'e' || currentLetter == 'k') {
                        total--;
                    }
                }
                //cout << i <<" " << j << " " <<total << " "<< lookingIndex % 5 << endl; 
                data[i][j] = {total, lookingIndex%5};
            }
        }
        //map<vector<int>, long long> memo;
        //cout << recurse(0, 0, 0, data, memo) << '\n';
        vector<vector<int> > dp (N, vector<int> (5));
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                if (i == N-1) {
                    dp[i][j] = data[i][j].first - (data[i][j].second * 2);
                } else {
                    int x = data[i][j].first;
                    int newEnd = data[i][j].second;
                    dp[i][j] = max(dp[i+1][j], dp[i+1][newEnd] + x);
                    dp[i][j] = max(dp[i][j], data[i][j].first - (data[i][j].second * 2));
                }
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
            //cout << endl;
        }
        cout << max(dp[0][0], 0) << '\n';
    }
    return 0;
}