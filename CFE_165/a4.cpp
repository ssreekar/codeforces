#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<int> arrA (N);
        vector<int> arrB (N);
        vector<pair<int, int> > data (N);
        for (int i = 0; i < N; i++) {
            cin >> arrA[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arrB[i];
            data[i] = {arrB[i], arrA[i]};
        }

        sort(data.rbegin(), data.rend());
        vector<long long> profits (N+1, 0);
        vector<long long> costs (N+1, 0);
        for (int i = N-1; i >= 0; i--) {
            profits[i] = profits[i+1];
            if (data[i].second < data[i].first) {
                profits[i] += data[i].first - data[i].second;
            }
            //cout << profits[i] << " ";
        }
        if (K == 0) {
            cout << profits[0] << "\n";
            continue;
        }
        //cout << '\n';
        priority_queue<long long > pq;
        long long totalCost = 0;
        for (int i = 0; i < N; i++) {
            long long value = data[i].second;
            if (i+1 < K) {
                costs[i] = -1;
                pq.push(value);
                totalCost += value;
            } else if (i+1 == K) {
                pq.push(value);
                totalCost += value;
                costs[i] = totalCost;
            } else {
                pq.push(value);
                totalCost += value;
                long long top = pq.top();
                totalCost -= top;
                pq.pop();
                costs[i] = totalCost;
            }
            //cout << costs[i] << " ";
        }
        //cout << '\n';
        long long minTotal = 0;
        for (int i = K-1; i < N; i++) {
            long long other = profits[i+1] - costs[i];
            minTotal = max(minTotal, other);
        }
        cout << minTotal << '\n';
    }
    return 0;
}