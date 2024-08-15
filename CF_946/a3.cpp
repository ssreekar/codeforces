#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void updateTotal(vector<vector<int> > &triplets, long long &total) {
    pair<int, int> signature = {-1, -1};
    int totalSigned = 0;
    int curSigned = 0;
    int lastValue = -1;
    vector<int> amounts;
    for (int i = 0; i < triplets.size(); i++) {
        //cout << triplets[i][0] << " " << triplets[i][1] << " " << triplets[i][2] << endl;
        if (signature.first == triplets[i][0] && 
            signature.second == triplets[i][1]) {
            if (triplets[i][2] == lastValue) {
                curSigned++;
                totalSigned++;
                //cout << "what " << curSigned << endl;
            } else {
                lastValue = triplets[i][2];
                amounts.push_back(curSigned);
                curSigned = 1;
                totalSigned++;
            }
        } else {
            amounts.push_back(curSigned);
            //cout << "HERE " << totalSigned  << endl;
            long long tempTotal = 0;
            for (int j = 0; j < amounts.size(); j++) {
                //cout << amounts[j] << endl;
                tempTotal += (totalSigned - amounts[j]) * amounts[j];
            }
            tempTotal /= 2;
            total += tempTotal;
            signature.first = triplets[i][0];
            signature.second = triplets[i][1];
            curSigned = 1;
            totalSigned = 1;
            amounts.clear();
            lastValue = triplets[i][2];
        }
    }
    //cout << total << endl << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        vector<vector<int> > triplets (N-2);
        for (int i = 0; i < N-2; i++) {
            vector<int> triplet = {arr[i], arr[i+1], arr[i+2]};
            //sort(triplet.begin(), triplet.end());
            triplets[i] = triplet;
        }
        vector<vector<int> > triplets2 (triplets.size());
        vector<vector<int> > triplets3 (triplets.size());
        long long total = 0;
        for (int i = 0; i < triplets.size(); i++) {
            triplets2[i] = {triplets[i][1], triplets[i][2], triplets[i][0]};
            triplets3[i] = {triplets[i][0], triplets[i][2], triplets[i][1]};
        }
        sort(triplets.begin(), triplets.end());
        sort(triplets2.begin(), triplets2.end());
        sort(triplets3.begin(), triplets3.end());
        triplets.push_back({-1, -1, -1});
        triplets2.push_back({-1, -1, -1});
        triplets3.push_back({-1, -1, -1});
        updateTotal(triplets, total);
        updateTotal(triplets2, total);
        updateTotal(triplets3, total);
        cout << total << '\n';
    }
    return 0;
}