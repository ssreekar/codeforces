#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    int oldL = 1;
    int l = 1;
    int r = 0;
    vector<int> zarray (input.size(), 0);
    map<int, int> counts;
    while(l < input.size()) {
        if (l > r) {
            oldL = l;
            r = l-1;
            while(r + 1 < input.size() && input[r+1] == input[r - l + 1]) {
                r++;
            }
            zarray[l] = r - l + 1;
            l++;
        } else {
            if (zarray[l - oldL] + l < r) {
                zarray[l] = zarray[l - oldL];
                l++;
            } else {
                while (r  < input.size() && input[r] == input[r - l]) {
                    r++;
                }
                r--;
                oldL = l;
                zarray[l] = r - l + 1;
                l++;
            }
        }
    }
    zarray[0] = zarray.size();
    for (int i = 0; i < zarray.size(); i++) {
        counts[zarray[i]]++;
    }
    int total = 0;
    map<int, int> results;
    for (auto it = counts.rbegin(); it != counts.rend(); it++) {
        //cout << it->first << " " << it->second << endl;
        total += it->second;
        results[it->first] = total;
    }
    //cout << endl << endl;

    int totalAmounts = 0;
    vector<vector<int> > ans;
    for (int i = input.size()-1; i >= 0; i--) {
        if (zarray[i] + i == zarray.size()) {
            totalAmounts++;
            ans.push_back({zarray[i], results[zarray[i]]});
        }
    }
    cout << totalAmounts << endl;
    for (auto line: ans) {
        cout << line[0] << " " << line[1] << endl;
    }

    return 0;
}