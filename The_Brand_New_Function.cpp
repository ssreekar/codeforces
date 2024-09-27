#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr (N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vector<vector<int> > nextIndex (N+1, vector<int> (20, -1));
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < 20; j++) {
            if ((1 << j) & arr[i]) {
                nextIndex[i][j] = i;
            } else {
                nextIndex[i][j] = nextIndex[i+1][j];
            }
        }
    }
    unordered_set<int> values;
    for (int i = 0; i < N; i++) {
        set<int> indexes;
        for (int j = 0; j < 20; j++) {
            if (nextIndex[i][j] != -1) {
                indexes.insert(nextIndex[i][j]);
            }
        }
        int value = arr[i];
        values.insert(value);
        //cout << value << " START " << endl;
        for (auto const& index : indexes) {
            value |= arr[index];
            //cout << index << endl;
            values.insert(value);
        }
    }
    cout << values.size() << '\n';
    return 0;
}