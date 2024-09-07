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

    const int TYPE = SUM;

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
        if (lazyTree[index] % 2 != 0) {
            lazyUpdate(index, lo, hi, lazyTree[index]);
            lazyTree[index] = 0;
        }
    }

    void lazyUpdate(int index, int lo, int hi, int x) {
        arr[index] = (hi - lo + 1) - arr[index];
        if (lo != hi) {
            lazyTree[index*2]+= 1;
            lazyTree[index*2+1] += 1;
        }
    }


    void build(vector<long long> &input, int index, int lo, int hi) {
        if (lo == hi) {
            arr[index] = input[lo];
            //cout << lo << " " << hi << " " << arr[index] << endl; 
        } else {
            int mid = (hi + lo) / 2;
            build(input, index*2, lo, mid);
            build(input, index*2+1, mid+1, hi);
            arr[index] = arr[index*2] + arr[index*2+1];
            //cout << lo << " " << hi << " " << arr[index] << endl; 
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
            //cout << lo << " " << hi << " " << arr[index] << endl; 
        } else if (left > hi || right < lo) {
            return;
        } else {
            int mid = (hi + lo) / 2;
            recurseUpdate(index*2, lo, mid, left, right, x);
            recurseUpdate(index*2+1, mid+1, hi, left, right, x);
            arr[index] = merge(arr[index*2], arr[index*2+1]);
            //cout << lo << " " << hi << " " << arr[index] << endl; 
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<long long> > arr (20, vector<long long> (N, 0) );
    for (int i = 0; i < N; i++) {
        long long input;
        cin >> input;
        int index = 0;
        while (input > 0) {
            arr[index][i] = input % 2;
            input /= 2;
            index++;
        }
    }
    vector<SegmentTree> forest;
    for (int i = 0; i < 20; i++) {
        //cout << "BUILDING I " << i << endl;
        SegmentTree tree (arr[i]);
        forest.push_back(tree);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long long l, r;
            cin >> l >> r;
            l--;
            r--;
            long long total = 0;
            long long multiply = 1;
            for (int index = 0; index < 20; index++) {
                long long amount = forest[index].query(l, r);
                amount *= multiply;
                total += amount;
                multiply *= 2;
            }
            cout << total << '\n';
        } else {
            long long l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            for (int index = 0; index < 20; index++) {
                if (x % 2) {
                    //cout << "UPDATING " << index << endl;
                    forest[index].update(l,r, 1);
                }
                x /= 2;
            }
        }
    }
    return 0;
}