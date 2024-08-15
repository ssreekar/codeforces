#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        string input;
        cin >> input;
        int indInput;
        vector<char> arr(M);
        set<int> indicies;
        for (int i = 0; i < M; i++) {
            cin >> indInput;
            indicies.insert(indInput);
        }
        for (int i = 0; i < M; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int arrInd = 0;
        for (auto it = indicies.begin(); it != indicies.end(); ++it) {
            int index = *it;
            //cout << index << "SKIBIDI2" << endl;
            //cout << arr[arrInd] << endl;
            input[index-1] = arr[arrInd];
            arrInd++;
        }
        //cout << "SKIBIDI" << endl;
        cout << input << '\n';
    }
    return 0;
}