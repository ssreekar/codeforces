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
        bool done = false;
        for (int i = 0; i < N-1; i++) {
            cout << "? " << i+1 << " " << 2 * N - i << endl;
            cout.flush();
            ll val;
            cin >> val;
            if (val == -1) {return 0;}
            if (val == 1) {
                cout << "! " << i+1 << endl;
                done = true;
                cout.flush();
                break; 
            }
        }
        if (done) {continue;}
        
        cout << "? " << N << " " << N-1 << endl;
        cout.flush();
        ll val;
        cin >> val;
        if (val == -1) {return 0;}
        if (val == 1) {
            cout << "! " << N << endl;
            cout.flush();
            continue;
        }
        cout << "? " << N << " " << N+2 << endl;
        cout.flush();
        cin >> val;
        if (val == -1) {return 0;}
        if (val == 1) {
            cout << "! " << N << endl;
            cout.flush();
            continue; 
        }
        cout << "! " << N+1 << endl;
        cout.flush();
    }
    return 0;
}