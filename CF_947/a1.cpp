#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int cases = 0; cases < test; cases++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        bool done = false;
        bool second = false;
        int lastVal = -1;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (lastVal > arr[i]) {
                if (second == false) {
                    second = true;
                } else {
                    done = true;
                }
            } 
            if (second && arr[i] > arr[0]) {
                done = true;
            }
            lastVal = arr[i];
        }
        if (done) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}