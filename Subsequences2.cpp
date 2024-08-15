#include <iostream>
#include <vector>

using namespace std;

struct fenwickTree {
    std::vector<long long> tree;

    fenwickTree(std::vector<long long> &arr) {
        tree.resize(arr.size()+1, 0);
        for (int i = 0; i < arr.size(); i++) {
            fenwickTree::insert(i, arr[i]);
        }
    }

    fenwickTree(long long size) {
        tree.resize(size+1, 0);
    }

    void insert(int index, long long value) {
        index++;
        while(index < tree.size()) {
            tree[index] += value;
            index += index & (-index);
        }
    }

    long long getSum(int index) {
        index++;
        long long total = 0;
        while(index > 0) {
            total += tree[index];
            index -= index & (-index);
        }
        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    K++;
    vector<long long> arr(N);
    vector<fenwickTree> dp;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= K; i++) {
        dp.push_back(fenwickTree(N));
    }

    // cout << "hi" << endl;

    dp[1].insert(0, 1);
    long long totalK = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            long long value = dp[j].getSum(arr[i]-1);
            // cout << value << " ";
            if (j < K && arr[i] < N) {
                dp[j+1].insert(arr[i], value);
            } 
            if (j == K) {
                totalK += value;
            }
        }
        // cout << endl;
    }
    cout << totalK << '\n';
    // cout << endl;

    return 0;
}


/*
1 1 1 1 1
0 1 2 3 3
0 0 1 3 3
*/