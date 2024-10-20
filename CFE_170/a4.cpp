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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<long long> arr (N);
    int counts[10010];
    memset(counts, 0, sizeof(counts));
    int dp[5010];
    memset(dp, 0, sizeof(dp));

    long long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    bool none = true;
    int points = 0;
    int start = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0 && !none) {
            counts[arr[i] + 5000]++;
        } else if (arr[i] == 0) {
            if (!none) {
                int newDp[5010];
                memset(newDp, 0, sizeof(newDp));
                for (int j = 0; j <= points; j++) {
                    int intPoints = j;
                    int strPoints = points - j;
                    newDp[j] = 
                }
            }
            none = false;
            points++;
            start = i + 1;
        }
    }


    return 0;
}