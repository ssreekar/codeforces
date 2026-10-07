#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vll arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            ll val = arr[i];
            ll bigger = 0;
            ll smaller = 0;
            for (int j = i+1; j < N; j++) {
                if (arr[j] > val) {
                    bigger++;
                }
                if (arr[j] < val) {
                    smaller++;
                }
            }
            cout << max(bigger, smaller) << " ";
        }
        cout << '\n';
    }
    return 0;
}