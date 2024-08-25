#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<vector<long long> > arr (3, vector<long long> (N));
        long long totalValue = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                if (i == 0) {totalValue += arr[i][j];}
            }
        }


        long long newValue = totalValue / 3;
        if (totalValue % 3 != 0) {
            newValue++;
        }
        bool valid = false;
        vector<long long> ordering = {0, 1, 2};
        do {
            long long curCount = 0;
            long long orderIndex = 0;
            vector<vector<long long> > startEnd (3);
            long long startIndex = 0;
            for (long long i = 0; i < N; i++) {
                curCount += arr[ordering[orderIndex]][i];
                if (curCount >= newValue) {
                    if (orderIndex < 2) {
                        startEnd[ordering[orderIndex]] = {startIndex, i};
                        startIndex = i+1;
                        orderIndex++;
                        curCount = 0;;
                    }
                }
            }
            if (curCount >= newValue && orderIndex == 2) {
                startEnd[ordering[orderIndex]] = {startIndex, N-1};
                for (long long i = 0; i < 3; i++) {
                    cout << startEnd[i][0] + 1<< " " << startEnd[i][1] + 1 << " ";
                }
                cout << '\n';
                valid = true;
                break;
            }
        } while (next_permutation(ordering.begin(), ordering.end()));

        if (!valid) {
            cout << "-1\n";
        }

    }
    return 0;
}