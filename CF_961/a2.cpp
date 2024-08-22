#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, M;
        cin >> N >> M;
        map<long long, long long> quantities;
        for (int i = 0; i < N; i++) {
            long long input;
            cin >> input;
            quantities[input]++;
        } 
        long long bestAmount = 0;


        for (auto it = quantities.begin(); it != quantities.end(); it++) {
            pair<long long, long long> first = *it;
            long long value = M / first.first;
            bestAmount = max(bestAmount, first.first * min(value, first.second));
        }
        for (auto it = quantities.begin(); next(it) != quantities.end(); it++) {
            pair<long long, long long> first = *it;
            pair<long long, long long> second = *next(it);
            if (first.first + 1 != second.first) {
                continue;
            }
            long long currentAmount = 0;
            long long value = M / second.first;
            long long newVal = second.first * min(value, second.second);
            long long secondUsed = min(value, second.second);
            long long remaining = M - newVal;
            value = remaining / first.first;
            newVal += first.first * min(value, first.second);
            long long firstLeft = first.second - min(value, first.second);
            remaining = M - newVal;
            if (firstLeft > 1 && remaining + min(firstLeft-1, secondUsed) >= first.first)  {
                bestAmount = max(bestAmount, M);
            }
            bestAmount = max(bestAmount, newVal);
        }
        cout << bestAmount << '\n';
    }
    return 0;
}