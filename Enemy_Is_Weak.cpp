#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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
    vector<long long> arr (N);
    vector<long long> sortedArr;
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    sortedArr = arr;
    sort(sortedArr.rbegin(), sortedArr.rend());
    unordered_map<long long, long long> inverseMap;
    for (int i = 0; i < N; i++) {
        inverseMap[sortedArr[i]] = i;
    }

    FenwickTree tree (N);
    FenwickTree tree2 (N);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        int index = inverseMap[arr[i]];
        long long below = tree.getVal(index);  
        long long seconds = tree2.getVal(index);
        total += seconds;
        tree2.insert(index, below);
        tree.insert(index, 1);
    }
    cout << total << '\n';
    return 0;
}