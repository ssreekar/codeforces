#include <iostream>
#include <vector>

using namespace std;

int findMin(int index, vector<char> &arr) {
    vector<int> values;
    for (int i = 0; i < arr.size(); i++) {
        if (i + 1 == index) {
            int num = (arr[i] - '0') * 10 + (arr[i+1] - '0'); 
            values.push_back(num);
            i++;
        } else {
            values.push_back(arr[i] - '0');
        }
    }
    int total = 0;
    bool nonOne = false;
    bool one = false;
    for (int i = 0; i < values.size(); i++) {
        //cout << values[i] << " ";
        if (values[i] == 0) {
            total = 0;
            one = false;
            nonOne = false;
            break;
        }
        if (values[i] != 1) {
            total += values[i];
            nonOne = true;
        } else {
            one = true;
        }
    }
    if (one == true && nonOne == false) {
        total = 1;
    }
    //cout << endl;
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<char> arr(N);
        bool zero = false;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        if (N == 2) {
            cout << ((arr[0] - '0') * 10) + (arr[1] - '0') << '\n';
            continue;
        }
        int globalMin = 1e9;
        for (int i = 1; i < N; i++) {
            globalMin = min(globalMin, findMin(i, arr));
        }
        cout << globalMin << '\n';
    }
    return 0;
}