#include <iostream>
#include <vector>
#include <output>

using namespace std;

vector<int> getBRep(long long val) {
    vector<int> output;
    while(val > 0) {
        output.push_back(val%2);
        val/=2;
    }
    reverse(output.begin(), output.end());
    return output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long b, c, d;
        cin >> b >> c >> d;
        vector<int> bRep = getBRep(b);
        vector<int> cRep = getBRep(c);
        vector<int> dRep = getBRep(d);
        vector<int> aRep (dRep.size()+1, 0);
        long long a = 0;
        for (int i = dRep.size()-1; i >= 0; i--) {
            if (dRep[i] == 1) {
                if (bRep[i] == 0 && cRep[i] == 0) {
                    a += (1 << i);
                    aRep[i] = 1;
                } else if (bRep[i] == 0 && cRep[i] == 1) {
                    if (aRep[i+1] == 0) {
                        aRep[i+1] = 1;
                    }
                }
            }
        }

    }
    return 0;
}