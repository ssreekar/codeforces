#include <iostream>
#include <vector>
#include <algorithm>

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

    sort(arr.begin(), arr.end());
    long long sum = 0;
    for (int i = 0; i < N / 2; i++) {
        sum += ((arr[i] + arr[N-i-1]) * (arr[i] + arr[N-i-1]));
    }
    cout << sum << endl;
    return 0;
}