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
        vector<int> arr (N);
        vector<int> permute (N);
        bool oddOne = false;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (arr[i] == 1 && i % 2 == 1) {
                oddOne = true;
            }
        }
        for (int i = oddOne ? 0 : 1; i < N; i+= 2) {
            permute[i] = N + 2 - arr[i];
        }
        vector<pair<int, int> > values;
        for (int i = oddOne ? 1 : 0; i < N; i+= 2) {
            values.push_back({arr[i], i});
        }
        sort(values.rbegin(), values.rend());
        for (int i = 1; i < values.size(); i++) {
            int valueIndex = values[i].second;
            permute[valueIndex] = N + 2 - values[i-1].first;
        }
        permute[values[0].second] = 1;
        for (int i = 0; i < permute.size(); i++) {
            cout << permute[i] << " ";
        }
        cout << endl;
    }
    return 0;
}