#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve (int lo, int hi, vector<pair<long long, long long> > &ranges, vector<vector<vector<long long> > > &dp) {
    if (dp[lo][hi][1] == -1) {
        ranges.push_back({lo, hi});
    } else if (dp[lo][hi][1] == -2) {
        return;
    } else {
        solve(dp[lo][hi][1], dp[lo][hi][2], ranges, dp);
        solve(dp[lo][hi][3], dp[lo][hi][4], ranges, dp);
    }
}

void subSolve(long long start, long long allEnd, long long amount, vector<pair<long long, long long> > &operations) {
    if (amount == 1) {
        return;
    } else if (amount == 2) {
        operations.push_back({start+1, start+1}); // 1
    } else {
        subSolve(start, allEnd-1, amount-1, operations);
        operations.push_back({start, allEnd});
        for (int i = start; i < allEnd; i++) {
            operations.push_back({i, i});
        }
        subSolve(start, allEnd-1, amount-1, operations);
    }
}

void rangeSolve(pair<long long, long long> pos, vector<pair<long long, long long> > &operations, vector<int> &arr) {
    for (int i = pos.first; i <= pos.second; i++) {
        if (arr[i] > 0) {
            operations.push_back({i, i});
        }
    }
    int count = pos.second - pos.first + 1;
    subSolve(pos.first, pos.second, count, operations);
    operations.push_back({pos.first, pos.second});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<vector<vector<long long> > > dp (N, vector<vector<long long> > (N));
    //cout << "???" << endl;
    for (int i = 0; i < N; i++) {
        if (arr[i] >= 1) {
            dp[i][i] = {arr[i], -2};
        } else {
            dp[i][i] = {1, -1, -1};
        }
    }
    //cout << "skibidi" << endl;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j + i - 1 < N; j++) {
            int endPoint = j + i - 1;
            vector<long long> maxVal = {i * i, -1};
            for (int midPoint = j; midPoint < endPoint; midPoint++) {
                //cout << i << " " << j << " " << midPoint << endl;
                long long newVal = dp[j][midPoint][0] + dp[midPoint+1][endPoint][0];
                if (maxVal[0] < newVal) {
                    maxVal = {newVal, j, midPoint, midPoint+1, endPoint}; 
                }
            }
            dp[j][endPoint] = maxVal;
        }
    }
    //cout << "made here" << endl;
    vector<pair<long long, long long> > ranges;
    solve(0, N-1, ranges, dp);
    cout << dp[0][N-1][0] << " ";
    vector<pair<long long, long long> > operations;
    for (int i = 0; i < ranges.size(); i++) {
        rangeSolve(ranges[i], operations, arr);
    }

    cout << operations.size() << '\n';
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i].first+1 << " " << operations[i].second+1 << '\n';
    }

    return 0;
}