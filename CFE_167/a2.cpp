#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        string A, B;
        cin >> A >> B;
        int bestValue = 1e9;
        for (int i = 0; i < B.size(); i++) {
            int bIndex = i;
            int aIndex = 0;
            int totalExtra = i;
            while(aIndex < A.size() && bIndex < B.size()) {
                if (A[aIndex] == B[bIndex]) {
                    bIndex++;
                }
                aIndex++;
            }
            if (bIndex < B.size()) {
                totalExtra += B.size() - bIndex;
            }
            bestValue = min(bestValue, totalExtra);
        }
        cout << bestValue + A.size() << "\n";
    }
    return 0;
}