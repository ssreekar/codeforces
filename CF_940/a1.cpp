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
        vector<int> arr (101, 0);
        int total = 0;
        for (int i = 0; i < N; i++){
            int input;
            cin >> input;
            arr[input]++;
            if (arr[input] % 3 == 0) {
                total++;
            }
        }
        cout << total << '\n';
    }
    return 0;
}