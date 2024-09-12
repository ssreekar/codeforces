#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> memo;

long long recurse(long long index, int mod, int M, bool first) {
    auto it = memo.find(index * 100 + mod);
    if (it != memo.end()) {
        return it->second;
    }
    //cout << index << " " << mod << " " << endl;
    if (index == 0) {
        return mod == 0 ? 1 : 0;
    }
    long long total = 0;
    long long newIndex = index;
    long long count = 1;
    long long actualDigit = 0;
    while(newIndex > 0) {
        long long dig = newIndex % 19;
        if (dig > 0 && !(count == 1 && first)) {
            long long newMod = mod * 10 + actualDigit;
            newMod %= M;
            long long testIndex = index - count;
            total += recurse(testIndex, newMod, M, false);
        }
        newIndex /= 19;
        count *= 19;
        actualDigit++;
    }
    memo[index * 100 + mod] = total;
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M;
    cin >> N >> M;
    vector<long long> occurances (10, 0);
    int digits = 0;
    while(N > 0) { 
        long long dig = N % 10;
        digits++;
        occurances[dig]++;
        N /= 10;
    }
    long long startIndex = 0;
    long long curMultiple = 1;
    for (int i = 0; i < occurances.size(); i++) {
        startIndex += occurances[i] * curMultiple;
        curMultiple *= 19;
    }

    cout << recurse(startIndex, 0, M, true) << '\n';

    return 0;
}