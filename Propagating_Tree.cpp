#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct FenwickTree {
    std::vector<long long> tree;

    static const int MIN = 0;
    static const int MAX = 1;
    static const int SUM = 2; 

    // CHANGE ACCORDING TO TYPE OF FENWICK TREE
    const int TYPE = SUM; 

    FenwickTree(std::vector<long long> &arr) {
        tree.resize(arr.size()+1, 0);
        if (TYPE != SUM) {
            for (int i = 0; i < arr.size(); i++) {
                FenwickTree::insert(i, arr[i]);
            }
        } else {
            // TODO Change faster insertion
            for (int i = 0; i < arr.size(); i++) {
                FenwickTree::insert(i, arr[i]);
            }
        }
    }

    FenwickTree(long long size) {
        tree.resize(size+1, 0);
    }

    void insert(int index, long long value) {
        index++;
        while(index < tree.size()) {
            tree[index] = operate(tree[index], value);
            index += index & (-index);
        }
    }

    long long getVal(int index) {
        index++;
        long long total = MIN ? numeric_limits<long long int>::max() : 0;
        while(index > 0) {
            total = operate(tree[index], total);
            index -= index & (-index);
        }
        return total;
    }

    long long operate(long long a, long long b) {
        switch (TYPE)
        {
        case SUM:
            return a + b;
        case MIN: 
            return min(a, b);
        case MAX:
            return max(a, b);
        }
        cerr << "Invalid Fenwick Tree Type" << endl;
        return -1;
    }
};

int recurse(int curNode, int curFree, vector<vector<int> > &adjList, vector<vector<long long> > &childrenArr, vector<long long> &startIndex, vector<bool> &visited,
            vector<int> &parents) {
    visited[curNode] = true;
    startIndex[curNode] = curFree;
    //cout << curNode << " " << curFree << endl;
    curFree++;
    int startFree = curFree;
    for (int i = 0; i < adjList[curNode].size(); i++) {
        int newNode = adjList[curNode][i];
        if (!visited[newNode]) {
            parents[newNode] = curNode;
            visited[newNode] = true;
            for (int j = 0; j < adjList[newNode].size(); j++) {
                int grandChild = adjList[newNode][j];
                if (!visited[grandChild]) {
                    parents[grandChild] = newNode;
                    //cout << "Going to " << grandChild << " " << curFree << endl;
                    curFree = recurse(grandChild, curFree, adjList, childrenArr, startIndex, visited, parents);
                }
            }
        }
    }
    childrenArr[curNode] = {startFree, curFree-1};
    return curFree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<long long> arr (N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vector<vector<int> > adjList (N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }
    vector<long long> startIndex (N, -1);
    vector<vector<long long> > childrenArr (N);
    vector<vector<long long> > childrenEven (N);
    vector<bool> visited (N, false);
    vector<int> parents (N);
    parents[0] = -1;
    int curFree = recurse(0, 0, adjList, childrenArr, startIndex, visited, parents);
    vector<bool> visited2 (N, false);
    visited2[0] = true;
    for (int i = 0; i < adjList[0].size(); i++) {
        int newNode = adjList[0][i];
        curFree = recurse(newNode, curFree, adjList, childrenArr, startIndex, visited2, parents);
    }
    for (int i = 0; i < N; i++) {
        int node = i;
        long long lo = 1e9;
        long long hi = -1;
        for (int j = 0; j < adjList[i].size(); j++) {
            int child = adjList[i][j];
            if (child != parents[node]) {
                lo = min(lo, childrenArr[child][0]-1);
                hi = max(hi, childrenArr[child][1]);
            }
        }
        if (lo == 1e9) {
            lo = 1;
            hi = 0;
        }
        childrenEven[node] = {lo, hi};
    }
    FenwickTree bTree (N+1);
    int prev = 0;
    vector<long long> newArr (N+1, 0);
    for (int i = 0; i < N; i++) {
        newArr[startIndex[i]] = arr[i];
    }
    for (int i = 0; i < N; i++) {
        bTree.insert(i, newArr[i] - prev);
        prev = newArr[i];
    }
    /*
    cout << "START" << endl;
    for (int i = 0; i < N; i++) {
        cout << bTree.getVal(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << i << endl <<  childrenArr[i][0] << " " << childrenArr[i][1] << endl;
        cout << childrenEven[i][0] << " " << childrenEven[i][1] << endl;
        cout << endl;
    } */
    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, val;
            cin >> x >> val;
            x--;
            bTree.insert(startIndex[x], val);
            bTree.insert(startIndex[x]+1, -1*val);
            bTree.insert(childrenArr[x][0], val);
            bTree.insert(childrenArr[x][1]+1, -1 * val); 
            bTree.insert(childrenEven[x][0], -1 * val);
            bTree.insert(childrenEven[x][1] + 1, val);
            /*cout  << "INSERT " << endl;
            for (int i = 0; i < N; i++) {
                cout << bTree.getVal(i) << " ";
            }
            cout << endl; */
        } else {
            int x;
            cin >> x;
            x--;
            /*cout << "UPDATE " << endl;
            for (int i = 0; i < N; i++) {
                cout << bTree.getVal(i) << " ";
            }
            cout << endl;
            */
            cout << bTree.getVal(startIndex[x]) << '\n';
        }
    }
    return 0;
}