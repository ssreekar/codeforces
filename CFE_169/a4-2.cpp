#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, Q;
        cin >> N >> Q;
        map<string, set<int> > info;
        vector<string> arr (N);
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            arr[i] = input;
            info[input].insert(i);
        }

        for (int i = 0; i < Q; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (arr[x][0] == arr[y][0] || arr[x][0] == arr[y][1] || arr[x][1] == arr[y][0] || arr[x][1] == arr[y][1] ) {
                cout << abs(y - x) << '\n';
                continue;
            }
            int maxVal = 1e9;
            for (auto &infoSet: info) {
                if (infoSet.first == arr[x] || infoSet.first == arr[y]) {
                    continue;
                }
                auto nextIt = infoSet.second.lower_bound(x);
                if (nextIt != infoSet.second.end()) {
                    maxVal = min(maxVal, abs(x - *nextIt) + abs(*nextIt - y));
                }
                if (nextIt != infoSet.second.begin()) {
                    nextIt--;
                    maxVal = min(maxVal, abs(x - *nextIt) + abs(y - *nextIt));
                }
            }
            if (maxVal > 1e8) {
                maxVal = -1;
            }
            cout << maxVal << '\n';
        }
        
    }
    return 0;
}