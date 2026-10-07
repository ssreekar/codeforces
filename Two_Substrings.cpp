#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    int aFirst = -1;
    int aLast = -1;
    int bFirst = -1;
    int bLast = -1;
    for (int i = 0; i+1 < input.size(); i++) {
        if (input[i] == 'A' && input[i+1] == 'B') {
            if (aFirst == -1) {
                aFirst = i;
            }
            aLast = i;
        }
        if (input[i] == 'B' && input[i+1] == 'A') {
            if (bFirst == -1){
                bFirst = i;
            }
            bLast = i;
        }
    }
    if (aFirst == -1 || bFirst == -1) {
        cout << "NO" << endl; 
        return 0;
    }
    if (abs(bLast - aFirst) > 1 || abs(bFirst - aLast) > 1) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}