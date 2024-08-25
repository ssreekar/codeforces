#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M;
    cin >> N >> M;
    vector<long long> arrA (N);
    vector<long long> arrB (N);
    vector<vector<long long> > data2;
    vector<vector<long long> > data (N);
    for (int i = 0; i < N; i++) {
        cin >> arrA[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arrB[i];
        data[i] = {arrA[i], arrB[i], arrA[i] - arrB[i]};
    }
     
    sort(data.begin(), data.end());
    int index = 0;
    while(index + 1 < data.size()){
        if (data[index][0] == data[index+1][0]) {
            data[index+1][1] = max(data[index][1], data[index+1][1]);
            data[index+1][2] = data[index+1][0] - data[index+1][1];
            index++;
        } else if (data[index][2] <= data[index+1][2]) {
            data[index+1][0] = data[index][0];
            data[index+1][1] = data[index][1];
            data[index+1][2] = data[index][2];
            index++;
        } else {
            data2.push_back(data[index]);
            index++;
        }
    }
    data2.push_back(data.back());
    //cout << "DATA SIZE " << data2.size() << endl;
    long long bestValue = data2.back()[0];
    vector<long long> dp (bestValue + 1, 0);
    int dataIndex = 0;
    for (int i = 1; i <= bestValue; i++) {
        while(dataIndex + 1 < data2.size() && data2[dataIndex+1][0] <= i ) {
            dataIndex++;
        }
        if (i >= data2[dataIndex][0]) {
            dp[i] = dp[i - data2[dataIndex][2]] + 2;
        } else {
            dp[i] = dp[i-1];
        }
    }

    long long total = 0;
    for (int i = 0; i < M; i++) {
        long long value;
        cin >> value;
        if (value > bestValue) {
            long long diff = data2.back()[2];
            value -= bestValue;
            total += 2;
            total += (value / diff) * 2;
            value %= diff;
            value += data2.back()[1];
            total += dp[value];
        } else {
            total += dp[value];
        }
    }
    cout << total << '\n';

    return 0;
}