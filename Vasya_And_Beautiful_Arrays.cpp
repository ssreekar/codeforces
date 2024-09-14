#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> arr (N+100);
    int lowest = 1e9;
    int highest = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        lowest = min(lowest, arr[i]);
        highest = max(highest, arr[i]);
    }
    vector<int> totalDiff (highest+K+100, 0);
    vector<int> totalCount (highest+K+100, 0);
    for (int i = 0; i < N; i++) {
        totalDiff[arr[i]]++; 
    }

    for (int i = 1; i < totalCount.size(); i++) {
        totalCount[i] = totalCount[i-1] + totalDiff[i];
    }

    if (K >= lowest) {
        cout << lowest << endl;
        return 0;
    }
    int bestValid = K;
    int maxIndex = totalCount.size() - 5;
    for (int i = K+1; i <= lowest; i++) {
        int totalz = 0;
        //cout << i << endl;
        for (int j = 0; j*i <= highest; j++) {
            int lowIndex = max(j * i - 1, 0);
            //cout <<  totalCount[(j*i)+K] << " " <<  totalCount[lowIndex] << " " << lowIndex << endl;
            totalz += totalCount[(j*i)+K] - totalCount[lowIndex];
            //cout << j << " " << totalz << endl;
        } 
        if (totalz == N) {
            bestValid = i;
        }
    }
    cout << bestValid << '\n';
    return 0;
}