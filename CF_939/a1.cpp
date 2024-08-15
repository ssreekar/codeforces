#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int K, Q;
        cin >> K >> Q;
        vector<int> arr(K);
        vector<int> queries(Q);
        for (int i = 0; i < K; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i];
        }
        for (int i = 0; i < Q; i++) {
            cout << min(arr[0] - 1, queries[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}