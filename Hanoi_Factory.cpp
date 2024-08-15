#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <limits>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


struct fenwickTree {
    std::vector<long long> tree;

    static const int MIN = 0;
    static const int MAX = 1;
    static const int SUM = 2; 

    // CHANGE ACCORDING TO TYPE OF FENWICK TREE
    const int TYPE = MAX; 

    fenwickTree(std::vector<long long> &arr) {
        tree.resize(arr.size()+1, 0);
        if (TYPE != SUM) {
            for (int i = 0; i < arr.size(); i++) {
                fenwickTree::insert(i, arr[i]);
            }
        } else {
            // TODO Change faster insertion
            for (int i = 0; i < arr.size(); i++) {
                fenwickTree::insert(i, arr[i]);
            }
        }
    }

    fenwickTree(long long size) {
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
    vector<vector<long long> > arr (N);
    vector<vector<long long> > filteredArr;
    vector<long long> innerArr;
    for (int i = 0; i < N; i++) {
        long long a, b, h;
        cin >> a >> b >> h;
        arr[i] = {b, a, h};
    }
    sort(arr.rbegin(), arr.rend());
    int index = 0;
    while(index < arr.size()) {
        if (index + 1 < arr.size() && arr[index][0] == arr[index+1][0]) {
            arr[index+1][1] = min(arr[index][1], arr[index+1][1]);
            arr[index+1][2] = arr[index][2] + arr[index+1][2];
        } else {
            filteredArr.push_back(arr[index]);
            innerArr.push_back(arr[index][1]);
            innerArr.push_back(arr[index][0]);
        }
        index++;
    }
    sort(innerArr.begin(), innerArr.end());
    unordered_map<long long, long long> innerMap;
    long long compressedIndex = 0;
    for (int i = 0; i < innerArr.size(); i++) {
        if (innerMap.find(innerArr[i]) == innerMap.end()) {
            innerMap[innerArr[i]] = compressedIndex;
            compressedIndex++;
        }
    }

    fenwickTree fTree = fenwickTree(innerArr.size());

    long long maxHeight = 0;
    for (int i = 0; i < filteredArr.size(); i++) {
        long long outer = filteredArr[i][0];
        long long inner = filteredArr[i][1];
        long long height = filteredArr[i][2];
        long long indexInner = innerMap[inner];
        long long indexOuter = innerMap[outer];
        if (indexOuter > 0) {
            height += fTree.getVal(indexOuter-1);
        }
        //cout << inner << " " << outer << " " << height << " " << index << endl;
        long long prevVal = fTree.getVal(indexInner);
        if (prevVal < height) {
            fTree.insert(indexInner, height);
        }
        maxHeight = max(maxHeight, height);
    }

    cout << maxHeight << endl;

    return 0;
}