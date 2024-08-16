#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<long long> initValues (N+1, 0);
        vector<long long> parents (N+1, -1);
        vector<long long> totalChildren (N+1, 0);
        vector<long long> values (N+1,  numeric_limits<long long int>::max());
        for (int i = 0; i < N; i++) {
            cin >> initValues[i+1];
        }
        for (int i = 1; i < N; i++) {
            long long input;
            cin >> input;
            parents[i+1] = input;
            totalChildren[input]++;
        }
        queue<long long> leafs;
        for (int i = 1; i < totalChildren.size(); i++) {
            if (totalChildren[i] == 0) {
                values[i] = initValues[i];
                leafs.push(i);
            }
        }


        while(!leafs.empty()) {
            long long node = leafs.front();
            long long value = values[node];
            //cout << node << " " << value << endl;
            leafs.pop();
            long long parent = parents[node];
            values[parent] = min(values[parent], value);
            totalChildren[parent]--;
            if (totalChildren[parent] == 0 && parent != 1) {
                if (initValues[parent] < values[parent]) {
                    long long diff = values[parent] - initValues[parent];
                    values[parent] = initValues[parent] + (diff / 2);
                }
                leafs.push(parent);
            }
        }

        cout << values[1] + initValues[1] << '\n';

    }
    return 0;
}