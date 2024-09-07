#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
    vector<long long> arr;
    vector<long long> lazyTree;
    long long N = 0;

    // Set Type of Segment Tree for Updates

    // Max Segment Tree
    static const int MAX = 0;

    // Min Segment Tree
    static const int MIN = 1;

    // Sum Segment Tree
    static const int SUM = 2;

    const int TYPE = MAX;

    // Constructor 
    SegmentTree (vector<long long> &input) {
        N = input.size();
        arr.resize(N * 4);
        lazyTree.resize(N * 4, 0);
        build(input, 1, 0, N - 1);
    }

    // Important Functions

    // Query (Max, Min, Sum) from range left to right
    long long query(int left, int right) {
        return recurseQuery(1, 0, N-1, left, right);
    }

    // Increment a[left...right] by x
    void update(int left, int right, int x) {
        recurseUpdate(1, 0, N-1, left, right, x);
    }

    // Merge function (Determines Segment Tree Type)
    long long merge(long long a, long long b) {
        if (TYPE == MAX) {
            return max(a, b);
        } else if (TYPE == MIN) {
            return min(a, b);
        } else if (TYPE == SUM) {
            return a + b;
        }
        cerr << "Invalid Type" << endl;
        return -1;
    }

    // Utility Functions
    void push(int index, int lo, int hi) {
        if (lazyTree[index] != 0) {
            lazyUpdate(index, lo, hi, lazyTree[index]);
            lazyTree[index] = 0;
        }
    }

    void lazyUpdate(int index, int lo, int hi, int x) {
        if (TYPE == MAX || TYPE == MIN) {
            arr[index] += x;
        } else if (TYPE == SUM) {
            arr[index] += x * (hi - lo + 1);
        }
        if (lo != hi) {
            lazyTree[index*2]+= x;
            lazyTree[index*2+1] += x;
        }
    }


    void build(vector<long long> &input, int index, int lo, int hi) {
        if (lo == hi) {
            arr[index] = input[lo];
        } else {
            int mid = (hi + lo) / 2;
            build(input, index*2, lo, mid);
            build(input, index*2+1, mid+1, hi);
            arr[index] = arr[index*2] + arr[index*2+1];
        }
    }

    long long recurseQuery(int index, int lo, int hi, int left, int right) {
        push(index, lo, hi);
        if (left <= lo && right >= hi) {
            return arr[index];
        } else if (left > hi || right < lo) {
            return 0;
        } else {
            int mid = (hi + lo) / 2;
            long long leftSum = recurseQuery(index*2, lo, mid, left, right);
            long long rightSum =  recurseQuery(index*2 + 1, mid+1, hi, left, right);
            return merge(leftSum, rightSum);
        }
    }

    void recurseUpdate(int index, int lo, int hi, int left, int right, int x) {
        push(index, lo, hi);
        if (left <= lo && right >= hi) {
            lazyUpdate(index, lo, hi, x);
        } else if (left > hi || right < lo) {
            return;
        } else {
            int mid = (hi + lo) / 2;
            recurseUpdate(index*2, lo, mid, left, right, x);
            recurseUpdate(index*2+1, mid+1, hi, left, right, x);
            arr[index] = merge(arr[index*2], arr[index*2+1]);
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    return 0;
}