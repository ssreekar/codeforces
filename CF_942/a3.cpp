#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, K;
        cin >> N >> K;
        vector<pair<long long, long long> > arr(N);
        for (int i = 0; i < N; i++) {
            long long input;
            cin >> input;
            arr[i] = {input, i+1};
        }
        sort(arr.begin(), arr.end());
        long long bestVal = arr[0].first;
        long long lastIndex = 0;
        for (int i = 0; i+1 < N; i++) {
            long long diff = arr[i+1].first - arr[i].first;
            if (K >= diff * (i + 1)) {
                K -= diff * (i + 1);
                bestVal = arr[i+1].first;
                lastIndex = i+1;
            } else {
                break;
            }
        }
        while(lastIndex < N) {
            if (arr[lastIndex].first <= bestVal) {
                lastIndex++;
            } else {
                break;
            }
        }

        bestVal += (K / lastIndex);
        K %= lastIndex;
        //cout << "Sets " << bestVal << '\n';
        bestVal --;
        bestVal *= N;
        bestVal++;
        bestVal += N - lastIndex;
        bestVal += K;
        cout << bestVal << '\n';
    
    }
    return 0;
}