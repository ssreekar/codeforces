#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int> > arr(5, vector<int> (5));
    int iVal = 0;
    int jVal = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                iVal = i;
                jVal = j;
            }
        }
    }
    cout << abs(2 - iVal) + abs(2 - jVal) << '\n';
    return 0;
}