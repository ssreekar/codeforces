#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        int ones = 0;
        int zeros = 0;
        int question = 0;
        unordered_map<int, int> counts;
        for (int i = 0; i < N-1; i++) {
            int a, b;
            cin >> a >> b;
            counts[a]++;
            counts[b]++;
        }
        string types;
        cin >> types;
        int extras = 0;

        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (it->second == 1 && it->first != 1) {
                char type = types[it->first-1];
                if (type == '1') {
                    ones++;
                } else if (type == '0') {
                    zeros++;
                } else {
                    question++;
                }
            } else if (it->first != 1) {
                if (types[it->first-1] == '?') {
                    extras++;
                }
            }
        }
        //cout << ones << " " << zeros << " " <<  question << endl;
        long long score = 0;
        if (types[0] == '?') {
            score = max(ones, zeros);
            if (max(ones, zeros) != min(ones, zeros)) {
                score += question / 2;
            } else {
                if (extras % 2 == 1) {
                    score += (question+1) / 2;
                } else {
                    score += question / 2;
                }
            }

        } else if (types[0] == '0'){
            score = ones;
            score += (question + 1)/ 2;
        } else {
            score = zeros;
            score += (question + 1) / 2;
        }
        cout << score << '\n';
    }
    return 0;
}