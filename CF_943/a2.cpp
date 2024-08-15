#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        string a, b;
        cin >> a >> b;
        int maxSize = 0;
        int bIndex = 0;
        for (int i = 0; i < a.size(); i++) {
            while(bIndex < b.size()) {
                if (a[i] == b[bIndex]) {
                    maxSize++;
                    bIndex++;
                    break;
                }
                bIndex++;
            }
        }
        cout << maxSize << '\n';
    }
    return 0;
}