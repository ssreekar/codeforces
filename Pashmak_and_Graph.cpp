#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int> > edges (M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    vector<long long> dp (N+1, 0);
    long long lastSize = -1;
    unordered_map<long long, long long> newVals;
    sort(edges.begin(), edges.end());
    long long totalMax = 0;
    for (int i = 0; i <= edges.size(); i++) {
        if (i == edges.size() || edges[i][0] > lastSize) {
            for (auto const&[key, value]: newVals) {
                dp[key] = value;
                totalMax = max(totalMax, value);
            }
            newVals.clear();
        } 
        if (i != edges.size()) {
            int u = edges[i][1];
            int v = edges[i][2];
            long long dpv = max(dp[v], 1 + dp[u]);
            newVals[v] = max(newVals[v], dpv); 
            lastSize = edges[i][0];
        }
    }
    cout << totalMax << '\n';



    return 0;
}