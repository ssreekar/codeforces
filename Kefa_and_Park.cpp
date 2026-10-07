#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector<ll> hasCat(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> hasCat[i];
    }
    vector<vector<ll> > adjList (N+1);
    for (int i = 0; i < N-1; i++) {
        ll a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    vector<bool> visited (N+1, false);
    vector<ll> longestAmount (N+1, 0);
    vector<ll> currentAmount (N+1, 0);
    queue<vll> bfs;
    bfs.push({1, 0, 0});
    ll finalVal = 0;
    while(!bfs.empty()) {
        vll top = bfs.front();
        ll node = top[0];
        ll prevAmount = top[1];
        ll prevLongest = top[2];
        bfs.pop();
        visited[node] = true;
        currentAmount[node] = hasCat[node] ? prevAmount + 1 : 0;
        longestAmount[node] = max(prevLongest, currentAmount[node]);
        bool isLeaf = true;
        for (int i = 0; i < adjList[node].size(); i++) {
            ll newNode = adjList[node][i];
            if (!visited[newNode]) {
                isLeaf = false;
                bfs.push({newNode, currentAmount[node], longestAmount[node]});
            }
        }
        if (isLeaf && longestAmount[node] <= M) {
            finalVal++;
        }
    }
    cout << finalVal << endl;

    return 0;
}