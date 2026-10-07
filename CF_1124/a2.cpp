#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

int rotateForward(int i) {
    int total = 0;
    while(i > 0) {
        int digit = i % 10;
        total += digit * digit;
        i /= 10;
    }
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
        vector<ll> arr (N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int times = 0; times <= 1010; times++) {
            for (int i = 0; i < N; i++) {
                arr[i] = rotateForward(arr[i]);
            }
        }
        int finalVal = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (arr[i] == arr[j]) {
                    finalVal ++;
                }  
            }
        }
        cout << finalVal << endl;
    }
    return 0;
}