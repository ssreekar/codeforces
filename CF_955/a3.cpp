#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, l, r;
        cin >> N >> l >> r;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        long long sum = 0;
        long long prevIndex = 0;
        long long total = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (sum >= l && sum <= r) {
                total++;
                sum = 0;
                prevIndex = i + 1;
            } else if (sum > r) {
                while(prevIndex <= i) {
                    sum -= arr[prevIndex];
                    prevIndex++;
                    if (sum >= l && sum <= r) {
                        total++;
                        sum = 0;
                        prevIndex = i + 1;
                        break;
                    } else if (sum < l) {
                        break;
                    }
                }
            }
        }
        cout << total << '\n';
    }
    return 0;
}