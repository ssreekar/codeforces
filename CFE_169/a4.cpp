#include <iostream>
#include <vector>

using namespace std;

int getIndex(char val) {
    if (val == 'B') {
        return 0;
    } else if (val == 'Y') {
        return 1;
    } else if (val == 'G') {
        return 2;
    }
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        long long N, Q;
        cin >> N >> Q;
        vector<vector<long long> > forward (N, vector<long long> (4, 1e9));
        vector<vector<long long> > backward (N, vector<long long> (4, 1e9));
        vector<vector<pair<long long, long long> > > forback (N, vector<pair<long long, long long> > (4));
        vector<vector<pair<long long, long long> > > backfor (N, vector<pair<long long, long long> > (4));
        vector<vector<long long> > colours (4);
        vector<vector<long long> > other (N);
        vector<vector<long long> > the (N);
        
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            int first = getIndex(input[0]);
            int second = getIndex(input[1]);
            colours[first].push_back(i);
            colours[second].push_back(i);
            forward[i][first] = i;
            backward[i][first] = i;
            forward[i][second] = i;
            backward[i][second] = i;
            forback[i][first] = {i, 0};
            backfor[i][first] = {i, 0};
            forback[i][second] = {i, 0};
            backfor[i][second] = {i, 0};
            for (int j = 0; j < 4; j++) {
                if (j != first && j != second) {
                    other[i].push_back(j);
                }
            }
            the[i].push_back(first);
            the[i].push_back(second);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < other[i].size(); j++) {
                int colour = other[i][j];
                int otherColour = other[i][(j+1) % 2];
                forward[i][colour] = forwardBSearch(colours[colour], i);
                backward[i][colour] = reverseBSearch(colours[colour], i);
                long long temp = forwardBSearch(colours[otherColour], i);
                long long temp2 = reverseBSearch(colours[colour], temp);
                forback[i][colour] = {temp2, temp - temp2};
                long long temp = reverseBSearch(colours[otherColour], i);
                long long temp2 = forwardBSearch(colours[colour], temp);
                backfor[i][colour] = {temp2, temp - temp2};
            }
        }

        for (int i = 0; i < Q; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            int first = the[y][0];
            int second = the[y][1];
            long long minVal = 1e9;
            minVal = min(minVal, abs(x - forward[x][first]) + abs(forward[x][first] - y));
            minVal = min(minVal, abs(x - backward[x][first]) + abs(backward[x][first] - y));
            minVal = min(minVal, abs(x - forward[x][second]) + abs(forward[x][second] - y));
            minVal = min(minVal, abs(x - backward[x][second]) + abs(backward[x][second] - y));
            pair<long long, long long> forbackFirst = forback[x][first];
            pair<long long, long long> forbackSecond = forback[x][second];
            pair<long long, long long> backForFirst = backfor[x][first];
            pair<long long, long long> backForSecond = backfor[x][second];
            minVal = min(minVal, abs(x - forbackFirst.first) + abs(forbackFirst.first - y) + forbackFirst.second);
            minVal = min(minVal, abs(x - forbackSecond.first) + abs(forbackSecond.first - y) + forbackSecond.second);
            minVal = min(minVal, abs(x - backForFirst.first) + abs(backForFirst.first - y) + backForFirst.second);
            minVal = min(minVal, abs(x - backForSecond.first) + abs(backForSecond.first - y) + backForSecond.second);
            cout << minVal << "\n";
        }
    }
    return 0;
}