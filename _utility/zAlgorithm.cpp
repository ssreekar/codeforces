#include <iostream>
#include <vector>

using namespace std;

vector<long long> zAlgorithm(string &input) {
    vector<long long> zArr (input.size(), 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < input.size(); i++) {
        if (i > r) {
            l = i;
            r = i;
            while (r < input.size() && input[r] == input[r-l]) {
                r++;
            }
            r--;
            zArr[i] = r - l + 1;
        } else {
            int offset = i - l;
            if (zArr[offset]  < r - i + 1) {
                zArr[i] = zArr[offset];
            } else {
                l = i;
                while (r < input.size() && input[r] == input[r-l]) {
                    r++;
                }
                r--;
                zArr[i] = r - l + 1;
            }
        }
    }
    return zArr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    return 0;
}