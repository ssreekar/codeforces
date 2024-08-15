#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N; 
        cin >> N;
        int totalOperations = 0;
        int totalSum = 0;
        vector<int> types;
        vector<int> index;
        int fullSum = (N * (N + 1)) / 2;
        for (int j = 0; j < N; j++) {
                types.push_back(1);
                index.push_back(j+1);
                totalSum += fullSum;
        }
        int prevVal = N;
        int Val = N-1;
        bool col = true;
        while(Val > 0) {
            for (int j = 0; j < Val; j++) {
                int type = col ? 2 : 1;
                types.push_back(type);
                index.push_back(j+1);
                int sum = (prevVal * (prevVal + 1)) / 2;
                totalSum += sum;
                totalSum -= prevVal * (j+1);
            }

            col = !col;
            prevVal = Val;
            Val = Val-1;
        }
        vector<bool> validIndex (types.size(), false);
        map<pair<int, int>, bool> visited;
        for (int j = types.size() - 1; j >= 0; j--) {
            pair<int, int> val (types[j], index[j]);
            if (visited.find(val) == visited.end()) {
                visited[val] = true;
                validIndex[j] = true;
                totalOperations++;
            }
        }
        cout << totalSum << " " << totalOperations << endl;
        for (int j = 0; j < types.size(); j++) {
            if (validIndex[j]) {
                cout << types[j] << " " << index[j] << " ";
                for (int k = 0; k < N; k ++) {
                    cout << k+1 << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}