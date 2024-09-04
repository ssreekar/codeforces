#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int findFarthest(vector<int> &distance, int start, vector<vector<int> > &adjList, unordered_set<int> &affected) {
    queue<int> bfs;
    bfs.push(start);
    distance[start] = 0;
    int maxDis = 0;
    int maxNode = start;
    while(!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        for (int i = 0; i < adjList[node].size(); i++){
            int otherNode = adjList[node][i];
            if (distance[node] + 1 < distance[otherNode]) {
                distance[otherNode] = distance[node] + 1;
                bfs.push(otherNode);
                if (affected.find(otherNode) != affected.end() && distance[otherNode] > maxDis) {
                    maxNode = otherNode;
                    maxDis = distance[otherNode];
                }
            }
        }
    }
    return maxNode;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, D;
    cin >> N >> M >> D;
    unordered_set<int> affected;
    int startNode = -1;
    for (int i = 0; i < M; i++) {
        int input;
        cin >> input;
        startNode = input;
        affected.insert(input);
    }
    vector<vector<int> > adjList (N+5);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    //cout << "made it" << endl;
    vector<int> distance1 (N+1, 1e9);
    vector<int> distanceEnd1 (N+1, 1e9);
    vector<int> distanceEnd2 (N+1, 1e9);
    int end1 = findFarthest(distance1, startNode, adjList, affected);
    int end2 = findFarthest(distanceEnd1, end1, adjList, affected);
    //cout << "second" << end2 << endl;
    findFarthest(distanceEnd2, end2, adjList, affected);
    int total = 0;
    for (int i = 1; i <= N; i++) {
        int node = i;
        if (max(distanceEnd1[node], distanceEnd2[node]) <= D) {
            total++;
        }
    }
    cout << total << '\n';
        
    return 0;
}