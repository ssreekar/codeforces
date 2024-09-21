#include <iostream>
#include <vector>
#include <stack>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int> > adjList (N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    stack<int> dfs;
    dfs.push(1);
    vector<int> arrivalTime (N+1, -1);
    vector<int> returnTime (N+1, -1);
    int curTime = 0;
    while(!dfs.empty()) {
        int top = dfs.top();
        dfs.pop();
        if (arrivalTime[top] != -1) {
            returnTime[top] = curTime;
            continue;
        }
        arrivalTime[top] = curTime;
        curTime++;
        dfs.push(top);
        for (int i = 0; i < adjList[top].size(); i++) {
            int newNode = adjList[top][i];
            if (arrivalTime[newNode] == -1){
                dfs.push(newNode);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << i << " " << arrivalTime[i] << " " << returnTime[i] << endl;
    }

    FenwickTree parents (N+1);
    FenwickTree childrens (N+1);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int c, v;
        cin >> c >> v;
        if (c == 1) {
            parents.insert(arrivalTime[v], 1);
            parents.insert(returnTime[v], -1);
        } else if (c == 2) {
            childrens.insert(arrivalTime[v], 1);
        } else {
            int parentVal = parents.getVal(arrivalTime[v]);
            int childrenVal = childrens.getVal(returnTime[v]-1);
            int other = arrivalTime[v] == 0 ? 0 : childrens.getVal(arrivalTime[v]-1);
            //cout <<  << endl;
        }
    }




    return 0;
}