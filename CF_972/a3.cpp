#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bSearch(vector<int> &arr, int input, bool below) {
    int lo = 0;
    int hi = arr.size() - 1;
    int valid = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        //cout << lo << " " << hi << " " << mid << " " << arr[mid] << " " << input << endl;
        if (arr[mid] > input) {
            if (below) {
                hi = mid - 1;
            } else {
                valid = arr[mid];
                hi = mid - 1;    
            }
        } else if (arr[mid] < input) {
            if (below) {
                valid = arr[mid];
                lo = mid + 1;
            } else {
                lo = mid + 1;
            }
        }
    }
    if (valid == -1) {
        if (below) {
            return -1;
        } else {
            return 1000000010;
        }
    }
    return valid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> arr (M);
        for (int i = 0; i < M; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < Q; i++) {
            int input;
            cin >> input;
            int highestBelow = bSearch(arr, input, true);
            int lowestAbove = bSearch(arr, input, false);
            if (highestBelow == -1) {
                cout << lowestAbove - 1 << '\n';
            } else if (lowestAbove == 1000000010) {
                cout << N - highestBelow << '\n'; 
            } else {
                cout << (lowestAbove - highestBelow) / 2 << '\n';
            }
            
        }

    }
    return 0;
}