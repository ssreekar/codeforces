#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> otherArr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        otherArr[arr[i]-1] = i+1;
    }
    for (int i = 0; i < N; i++) {
        cout << otherArr[i] << " ";
    }
    cout << '\n';

    return 0;
}