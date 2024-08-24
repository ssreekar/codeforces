#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<int> arr (N);
        vector<long long> prefixSum (N+1, 0);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            prefixSum[i+1] = prefixSum[i] + arr[i];
        }
        string input;
        cin >> input;
        long long total = 0;
        bool start = false;
        int startIndex = -1;
        int endIndex = -1;
        for (int i = 0; i < N; i++){
            if (!start && input[i] == 'L') {
                start = true;
                startIndex = i;
            }
            if (input[i] == 'R') {
                endIndex = i;
            }
        }
        //cout << startIndex << " " << endIndex << endl;
        if (startIndex != -1 && endIndex != -1) {
            while(startIndex <= endIndex) {
                if (input[startIndex] == 'L' && input[endIndex] == 'R') {
                    total += prefixSum[endIndex+1] - prefixSum[startIndex];
                    startIndex++;
                    endIndex--;
                } else {
                    if (input[startIndex] != 'L') {
                        startIndex++;
                    }
                    if (input[endIndex] != 'R') {
                        endIndex--;
                    }
                }
            }
        }
        cout << total << '\n';
    }
    return 0;
}