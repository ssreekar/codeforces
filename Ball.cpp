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
    vector<vector<long long> > arr(N, vector<long long> (3));
    vector<long long> arrI (N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[i][1];
        arrI[i] = arr[i][1];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[i][2];
    }
    sort(arrI.rbegin(), arrI.rend());
    unordered_map<long long, long long> mapperI; 
    long long compressedIndex = 0;
    for (int i = 0; i < arrI.size(); i++) {
        if (mapperI.find(arrI[i]) == mapperI.end()) {
            mapperI[arrI[i]] = compressedIndex;
            compressedIndex++;
        }
    }

    sort(arr.rbegin(), arr.rend());

    fenwickTree fTree = fenwickTree(compressedIndex);
    
    long long count = 0;
    vector<vector<long long> > stack;
    for (int i = 0; i < arr.size(); i++) {
        //cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
        long long index = mapperI[arr[i][1]];
        if (index > 0) {
            long long  maxVal = fTree.getVal(index-1);
            if (maxVal > arr[i][2]) {
                count++;
            }
        }
        stack.push_back({index, arr[i][2]});
        if (i + 1 >= arr.size() || arr[i+1][0] != arr[i][0]) {
            for (int j = 0; j < stack.size(); j++) {
                if (fTree.getVal(stack[j][0]) < stack[j][1]) {
                    fTree.insert(stack[j][0], stack[j][1]);
                }
            }
            stack.clear();
        }
    }

    std::cout << count << '\n';

    
    return 0;
}