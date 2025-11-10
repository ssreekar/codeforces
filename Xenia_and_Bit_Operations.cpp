// https://codeforces.com/problemset/problem/339/D

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

// Calculate 2^N
long long fastPow2(long long N) {
    long long curr = 1;
    long long pow2 = 2;
    while (N > 0) {
        if (N & 1) {
            curr *= pow2;
        }
        pow2 *= pow2;
        N = N >> 1;
    }
    return curr;
}

struct SegmentTree {
    vector<long long> arr;
    long long N = 0;
    long long DEPTH = 0;

    // Set Type of Segment Tree for Updates

    // Max Segment Tree
    static const int MAX = 0;

    // Min Segment Tree
    static const int MIN = 1;

    // Sum Segment Tree
    static const int SUM = 2;

    const int TYPE = MAX;

    // Constructor 
    SegmentTree (vector<long long> &input, int depth) {
        N = input.size();
        DEPTH = depth;
        arr.resize(N * 4);
        build(input, 1, 0, N - 1, depth);
    }

    // Important Functions

    // Query (Max, Min, Sum) from range left to right
    long long query() {
        return arr[1];
    }

    // Increment a[index] to x
    void update(int index, ll x) {
        recurseUpdate(1, 0, N-1, index, index, x, DEPTH);
    }

    // Merge function (Determines Segment Tree Type)
    long long merge(long long a, long long b, int depth) {
        if (depth & 1) { // Odd Depth OR
            return a | b;
        } else {
            return a ^ b;
        }
    }

    void build(vector<long long> &input, int index, int lo, int hi, int depth) {
        if (lo == hi) {
            //cout << index << " " << input[lo] << endl;
            arr[index] = input[lo];
        } else {
            int mid = lo + (hi - lo) / 2;
            build(input, index*2, lo, mid, depth-1);
            build(input, index*2+1, mid+1, hi, depth-1);
            arr[index] = merge(arr[index*2], arr[index*2+1], depth);
            //cout << index << " " << arr[index] << endl;
        }
    }

    void recurseUpdate(int index, int lo, int hi, int left, int right, ll x, int depth) {
        if (left <= lo && right >= hi) {
            arr[index] = x;
            //cout << index << " " << x << endl;
        } else if (left > hi || right < lo) {
            return;
        } else {
            int mid = lo + (hi - lo) / 2;
            recurseUpdate(index*2, lo, mid, left, right, x, depth-1);
            recurseUpdate(index*2+1, mid+1, hi, left, right, x, depth-1);
            arr[index] = merge(arr[index*2], arr[index*2+1], depth);
            //cout << index << " " << arr[index] << " - " << depth << endl;
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    ll arrSize = fastPow2(N);
    //cout << arrSize << endl;
    vll arr (arrSize);
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    SegmentTree tree(arr, N);
    for (int i = 0; i < M; i++) {
        ll Q, B;
        cin >> Q >> B;
        tree.update(Q-1, B);
        cout << tree.query() << endl;
    }
    return 0;
}