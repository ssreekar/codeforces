#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T;
    cin >> T;
    for (long long cases = 0; cases < T; cases++) {
        long long N, M;
        cin >> N >> M;
        vector<vector<long long> > data (N);
        for (long long i = 0; i < N; i++) {
            long long L;
            cin >> L;
            unordered_set<long long> values;
            for (long long j = 0; j < L; j++) {
                long long input;
                cin >> input;
                values.insert(input);
            }
            long long lowestVal = 0;
            while(values.find(lowestVal) != values.end()) {
                lowestVal++;
            }
            long long secondLowest = lowestVal+1;
            while(values.find(secondLowest) != values.end()) {
                secondLowest++;
            }
            data[i] = {secondLowest, lowestVal};
        } 
        sort(data.rbegin(), data.rend());
        long long total = 0;
        long long curF = 0;
        for (long long i = 0; i < data.size(); i++) {
            if (data[i][1] >= curF) {
                long long additions = data[i][1] - curF + 1;
                if (M >= additions) {
                    total += additions * data[i][0];
                    M -= additions;
                    curF = data[i][1] + 1;
                } else {
                    total += M * data[i][0];
                    M = 0;
                    break;
                }
            }
        }
        if (M > 0) {
            total += ((curF + M) * (M - curF + 1)) / 2;
        }
        cout << total << '\n';

    }
    return 0;
}