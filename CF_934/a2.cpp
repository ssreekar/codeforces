#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        vector<int> arr (2 * N);
        vector<vector<int> > data (N+1);
        for (int i = 0; i < 2 * N; i++) {
            cin >> arr[i];
            data[arr[i]].push_back(i);
        }
        vector<int> firstDoubles;
        vector<int> secondDoubles;
        vector<int> firstVal;
        vector<int> secondVal;
        for (int i = 1; i <= N; i++) {
            bool first = data[i][0] < N;
            int second = data[i][1] < N;
            if (first && second) {
                firstDoubles.push_back(i);
            } else if (!first && !second) {
                secondDoubles.push_back(i);
            } else {
                if (firstVal.size() < 2 * K) {
                    firstVal.push_back(i);
                    secondVal.push_back(i);
                }
            }
        }
        int firstIndex = 0;
        int secondIndex = 0;
        if (firstVal.size() % 2 == 1) {
            firstVal.pop_back();
            secondVal.pop_back();
        }
        while (firstVal.size() < 2 * K) {
            firstVal.push_back(firstDoubles[firstIndex]);
            secondVal.push_back(secondDoubles[secondIndex]);
            firstVal.push_back(firstDoubles[firstIndex]);
            secondVal.push_back(secondDoubles[secondIndex]);
            firstIndex+= 1;
            secondIndex+= 1;
        }
        for (int i = 0; i < firstVal.size(); i++) {
            cout << firstVal[i] << " ";
        }
        cout << '\n';
        for (int i = 0; i < secondVal.size(); i++) {
            cout << secondVal[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}