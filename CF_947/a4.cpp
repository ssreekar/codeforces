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
        int N;
        cin >> N;
        int a, b;
        cin >> a >> b;
        vector<vector<int> > adj (N+1);
        for (int i = 0; i < N-1; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        queue<pair<int, int> > q; 
        vector<int> dis (N+1, 1e8);
        vector<int> parents (N+1, -1);
        dis[a] = 0;
        q.push({a, 0});
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int curNode = top.first;
            int curDis = top.second;
            for (int i = 0; i < adj[curNode].size(); i++) {
                int newNode = adj[curNode][i];
                if (dis[newNode] > dis[curNode] + 1) {
                    dis[newNode] = dis[curNode] + 1;
                    parents[newNode] = curNode;
                    q.push({newNode, dis[newNode]});
                }
            }
        }
        
        int travelDis = dis[b] / 2;
        int altTravelDis = dis[b] - travelDis;
        
        int startNode = b;
        for (int i = 0; i < altTravelDis; i++) {
            startNode = parents[startNode];
        }

        for (int i = 0; i < N+1; i++) {
            dis[i] = 1e8;
            parents[i] = -1;
        }
        dis[startNode] = 0;
        q.push({startNode, 0});
        int maxDepth = 0;
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int curNode = top.first;
            int curDis = top.second;
            for (int i = 0; i < adj[curNode].size(); i++) {
                int newNode = adj[curNode][i];
                if (dis[newNode] > dis[curNode] + 1) {
                    dis[newNode] = dis[curNode] + 1;
                    parents[newNode] = curNode;
                    q.push({newNode, dis[newNode]});
                    maxDepth = max(maxDepth, dis[newNode]);
                }
            }
        }
        
        int finalDis = altTravelDis + ((N-1) * 2) - maxDepth;
        //cout << "Alt Dis " << altTravelDis << endl;
        //cout << "Max Depth " << maxDepth << endl;
        //cout << "Start Node " << startNode << endl;
        cout << finalDis << endl;
    }
    return 0;
}