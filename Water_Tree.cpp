#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

struct SegmentTree {
    vector<long long> segTree;
    long long N = 0;

    SegmentTree(int size) {
        segTree.resize(4 * size, 0);
        N = size;
    }

    void color(int left, int right) {
        colorRecurse(1, 0, N-1, left, right);
    }

    void uncolor (int index) {
        uncolorRecurse(1, 0, N-1, index);
    }

    int getColor(int left, int right) {
        return getColorRecurse(1, 0, N-1, left, right);
    }

    void push(int index, int segLeft, int segRight) {
        if (segTree[index] == 1) {
            if (segLeft != segRight) {
                segTree[index*2] = 1;
                segTree[index*2+1] = 1;
            }
        }
    }

    int getColorRecurse(int index, int segLeft, int segRight, int arrLeft, int arrRight) {
        push(index, segLeft, segRight);
        if (segLeft > arrRight || segRight < arrLeft) {
            return 1;
        }
        if (segLeft >= arrLeft && segRight <= arrRight) {
            return segTree[index];
        }
        int mid = (segLeft + segRight) / 2;
        int left = getColorRecurse(index*2, segLeft, mid, arrLeft, arrRight);
        int right = getColorRecurse(index*2+1, mid+1, segRight, arrLeft, arrRight);
        return min(left, right);
    }

    int uncolorRecurse(int index, int segLeft, int segRight, int arrIndex) {
        //cout << index << " " << segLeft << " " << segRight << " " << arrIndex << endl;
        push(index, segLeft, segRight);
        if (segLeft > arrIndex || segRight < arrIndex) {
            return segTree[index];
        }
        segTree[index] = 0;
        if (segLeft == segRight && segLeft == arrIndex) {
            return segTree[index];
        }
        int mid = (segLeft + segRight) / 2;
        int left = uncolorRecurse(index*2, segLeft, mid, arrIndex);
        int right = uncolorRecurse(index*2+1, mid+1, segRight, arrIndex);
        segTree[index] = min(left, right);
        return segTree[index];
    }
    

    int colorRecurse(int index, int segLeft, int segRight, int arrLeft, int arrRight) {
        //cout << index << " " << segLeft << " " << segRight << " " << arrLeft << " " << arrRight << endl;
        push(index, segLeft, segRight);
        if (segRight < arrLeft || segLeft > arrRight) {
            return segTree[index];
        }
        if (segLeft >= arrLeft && segRight <= arrRight) {
            segTree[index] = 1;
            return segTree[index];
        }
        int mid = (segLeft + segRight) / 2;
        int left = colorRecurse(index*2, segLeft, mid, arrLeft, arrRight);
        int right = colorRecurse(index*2+1, mid+1, segRight, arrLeft, arrRight);
        segTree[index] = min(left, right);
        return segTree[index];
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
    vector<int> parentNode (N+1, -1);
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
                parentNode[newNode] = top;
                dfs.push(newNode);
            }
        }
    }


    // arrival Time is at node // Return Time is 1 plus last child

    SegmentTree segTree (N+1);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int c, v;
        cin >> c >> v;
        if (c == 1) { 
            //cout << arrivalTime[v] << " " <<returnTime[v]-1 << endl;
            int isColoured = segTree.getColor(arrivalTime[v], returnTime[v]-1);
            if (!isColoured && parentNode[v] != -1 ) {
                segTree.uncolor(arrivalTime[parentNode[v]]);
            }
            segTree.color(arrivalTime[v], returnTime[v]-1);
            
        } else if (c == 2) {
            //cout << arrivalTime[v] << endl;
            segTree.uncolor(arrivalTime[v]);
        } else {
            //cout << arrivalTime[v] << " " <<returnTime[v]-1 << endl;
            int value = segTree.getColor(arrivalTime[v], returnTime[v]-1);
            cout << value << '\n';
        }
    }




    return 0;
}