#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long djikstra(int startM, int startR, vector<vector<pair<int, int> > > &adjList, vector<long long> &disNoHorseM, vector<long long> &disHorseM,vector<long long> &disNoHorseR, vector<long long> &disHorseR,  vector<bool> &horses) {
    priority_queue<vector<long long>, vector<vector<long long> >, greater<vector<long long> > > pq;
    vector<bool> completedM (startR + 1, false);
    vector<bool> completedR (startR + 1, false);
    disNoHorseM[startM] = 0;
    disNoHorseR[startR] = 0;
    pq.push({0, startM, 0, 0});
    pq.push({0, startR, 0, 1});
    while(!pq.empty()) {
        vector<long long> top = pq.top();
        pq.pop();
        long long distance = top[0];
        long long node = top[1];
        long long horse = top[2];
        long long person = top[3];
        if (person == 0) {
            completedM[node] = true;
        } else {
            completedR[node] = true;
        }
        long long disM = min(disHorseM[node], disNoHorseM[node]);
        long long disR = min(disHorseR[node], disNoHorseR[node]);
        if (completedM[node] && completedR[node]) {
            return max(disM, disR);
        }
        if (horses[node] && horse == 0) {
            horse = 1;
            if (person == 0) {
                disHorseM[node] = min(disHorseM[node], disNoHorseM[node]);
            } else {
                disHorseR[node] = min(disHorseR[node], disNoHorseR[node]);
            }
            
        }
        //cout << node << " " << distance << " " << horse << endl;
        for (int i = 0; i < adjList[node].size(); i++) {
            long long newNode = adjList[node][i].first;
            long long newRoad = adjList[node][i].second;
            if (horse) {
                if (person == 0) {
                    if (disHorseM[newNode] > distance + (newRoad / 2)) {
                        disHorseM[newNode] = distance + (newRoad / 2);
                        pq.push({disHorseM[newNode], newNode, 1, person});
                    }
                } else {
                    if (disHorseR[newNode] > distance + (newRoad / 2)) {
                        disHorseR[newNode] = distance + (newRoad / 2);
                        pq.push({disHorseR[newNode], newNode, 1, person});
                    }
                }

            } else {
                if (person == 0) {
                    if (disNoHorseM[newNode] > distance + newRoad && disHorseM[newNode] > distance + newRoad) {
                        disNoHorseM[newNode] = distance + newRoad;
                        int newHorse = horses[newNode] ? 1 : 0;
                        pq.push({disNoHorseM[newNode], newNode, newHorse, person});
                    }
                } else {
                    if (disNoHorseR[newNode] > distance + newRoad && disHorseR[newNode] > distance + newRoad) {
                        disNoHorseR[newNode] = distance + newRoad;
                        int newHorse = horses[newNode] ? 1 : 0;
                        pq.push({disNoHorseR[newNode], newNode, newHorse, person});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M, H;
        cin >> N >> M >> H;
        vector<bool> horses (N+1, false);
        for (int i = 0; i < H; i++) {
            int input;
            cin >> input;
            horses[input] = true;
        }
        vector<vector<pair<int, int> > > adjList (N+1);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<long long> disNoHorseM (N+1, 1e14);
        vector<long long> disHorseM (N+1, 1e14);
        vector<long long> disNoHorseR (N+1, 1e14);
        vector<long long> disHorseR (N+1, 1e14);
        //cout << "M 1" << endl << endl;
        cout << djikstra(1, N, adjList, disNoHorseM, disHorseM, disNoHorseR, disHorseR, horses) << '\n';


    }
    return 0;
}