#include <iostream>
#include <vector>

using namespace std;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K;
        cin >> N >> K;
        //int logN = log2_floor(N);
        vector<int> ans;
        for (int i = 1; i <= N; i*= 2) {
            if (i < K && i*2 > K) {
                ans.push_back(K-i);
                if (i*2-1 == K) {
                    ans.push_back(K+2);
                } else {
                    ans.push_back(K+1);
                    ans.push_back(K+1);
                }
            } else if (i == K) { 
                if (i == 1) {
                    ans.push_back(3);
                } else {
                    ans.push_back(K+1);
                    ans.push_back(K+1);
                }
            } else {    
                ans.push_back(i);
            }
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}