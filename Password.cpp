#include <iostream>
#include <vector>
#include <unordered_set>

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
    string s;
    cin >> s;
    vector<long long> zArr = zAlgorithm(s);
    long long maxMiddle = 0;
    long long count = 0;
    for (int i = 0; i < zArr.size(); i++) {
        if (i + zArr[i] == zArr.size()) {
            if (maxMiddle >= zArr[i]) {
                count = max(zArr[i], count);
            }
            maxMiddle = max(zArr[i]-1, maxMiddle);
        } else {
            maxMiddle = max(zArr[i], maxMiddle);
        }
    }

    if (count == 0) {
        cout << "Just a legend\n"; 
    } else {
        cout << s.substr(0, count) << '\n';
    }


    return 0;
}