#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, C;
        cin >> N >> C;
        vector<long long> arr (N+1);
        vector<vector<long long> > adjList(N+1);
        for (int i = 1; i < N+1; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N-1; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<long long> yesCase (N+1, 0);
        vector<long long> noCase (N+1, 0);
        vector<bool> visited (N+1, false);
        vector<long long> outDegree (N+1, 0);
        queue<int> leafs;
        for (int i = 1; i <= N; i++) {
            //cout << i << " " << adjList[i].size() << endl;
            if (adjList[i].size() <= 1) {
                leafs.push(i);
            }
            outDegree[i] = adjList[i].size();
        }
        long long bestAns = 0;
        while(!leafs.empty()) {
            int node = leafs.front();
            leafs.pop();
            if (visited[node]){continue;}
            visited[node] = true;
            yesCase[node] += arr[node];
            bestAns = max(yesCase[node], bestAns);
            bestAns = max(noCase[node], bestAns);
            //cout << node << " " << yesCase[node] << " " << noCase[node] << endl;
            for (int i = 0; i < adjList[node].size(); i++) {
                int newNode = adjList[node][i];
                if (!visited[newNode]) {
                    yesCase[newNode] += max(yesCase[node] - (2 * C), noCase[node]);
                    noCase[newNode] += max(yesCase[node], noCase[node]);
                    outDegree[newNode]--;
                    if (outDegree[newNode] <= 1) {
                        leafs.push(newNode);
                    }
                }
            }
        }
        cout << bestAns << '\n';
    }
    return 0;
}