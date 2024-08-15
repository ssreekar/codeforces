#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        if ((p1 + p2 + p3) % 2 != 0) {
            cout << -1 << endl;
        } else {
            int total = 0;
            vector<int> arr = {p1, p2, p3};
            while(true) {
                sort(arr.begin(), arr.end());
                //cout << arr[1] << endl; 
                if (arr[1] == 0) {
                    break;
                } else {
                    arr[1] -= 1;
                    arr[2] -= 1;
                    total++;
                }
            }
            cout << total << endl;
        }
    }
    return 0;
}