#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

void test(ll i, ll j, vector<vector<char> > &grid, vector<vector<bool> > &visited, queue<pair<ll,ll> > &bfs, ll &S) {
    if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size() || S <= 0) {
        return;
    }
    if (visited[i][j] == false && grid[i][j] == '.') {
        visited[i][j] = true;
        S--;
        bfs.push({i, j});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, K;
    cin >> N >> M >> K;
    ll startI, startJ;
    ll S = 0;
    vector<vector<char> > grid (N, vector<char> (M));
    vector<vector<bool> > visited (N, vector<bool> (M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                S++;
                startI = i;
                startJ = j;
            }
        }
    }
    S -= K;
    visited[startI][startJ] = true;
    S--;
    queue<pair<ll,ll> > bfs;
    bfs.push({startI, startJ});
    while(!bfs.empty() && S != 0) {
        pair<ll, ll> top = bfs.front();
        bfs.pop();
        ll iIndex = top.first;
        ll jIndex = top.second;
        test(iIndex+1, jIndex, grid, visited, bfs, S);
        test(iIndex-1, jIndex, grid, visited, bfs, S);
        test(iIndex, jIndex+1, grid, visited, bfs, S);
        test(iIndex, jIndex-1, grid, visited, bfs, S);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] != true && grid[i][j] == '.') {
                cout << "X";
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}