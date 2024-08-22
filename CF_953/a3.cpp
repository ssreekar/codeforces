#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, K;
        cin >> N >> K;
        if (K % 2 != 0) {
            cout << "No\n";
            continue;
        }
        long long frontIndex = 0;
        long long backIndex = N-1;
        vector<long long> arr (N);
        for (int i = 0; i < N; i++) {
            arr[i] = i+1;
        }
        bool complete = false;
        while(frontIndex <= backIndex) {
            long long maxValue = (backIndex - frontIndex) * 2;
            if (K <= maxValue) {
                K /= 2;
                swap(arr[frontIndex], arr[frontIndex+K]);
                complete = true;
                break;
            } else {
                swap(arr[frontIndex], arr[backIndex]);
                K -= maxValue;
                frontIndex++;
                backIndex--;
            }
        }
        if (!complete) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n';
        }

    }
    return 0;
}