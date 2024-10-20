#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <chrono>
#include <climits>

using namespace std;

struct SegmentTreeMax {
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
    SegmentTreeMax (vector<long long> &input) {
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


    void build(vector<long long> &input, int index, int lo, int hi) {
        if (lo == hi) {
            arr[index] = input[lo];
        } else {
            int mid = (hi + lo) / 2;
            build(input, index*2, lo, mid);
            build(input, index*2+1, mid+1, hi);
            arr[index] = merge(arr[index*2], arr[index*2+1]);
        }
    }

    long long recurseQuery(int index, int lo, int hi, int left, int right) {
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
};

struct SegmentTreeMin {
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

    const int TYPE = MIN;

    // Constructor 
    SegmentTreeMin (vector<long long> &input) {
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

    long long getSentinel() {
        if (TYPE == MAX || TYPE == SUM) {
            return 0;
        } else if (TYPE == MIN) {
            return LLONG_MAX;
        }
        cerr << "Invalid Type" << endl;
        return -1;
    }


    void build(vector<long long> &input, int index, int lo, int hi) {
        if (lo == hi) {
            arr[index] = input[lo];
        } else {
            int mid = (hi + lo) / 2;
            build(input, index*2, lo, mid);
            build(input, index*2+1, mid+1, hi);
            arr[index] = merge(arr[index*2], arr[index*2+1]);
        }
    }

    long long recurseQuery(int index, int lo, int hi, int left, int right) {
        if (left <= lo && right >= hi) {
            return arr[index];
        } else if (left > hi || right < lo) {
            return getSentinel();
        } else {
            int mid = (hi + lo) / 2;
            long long leftSum = recurseQuery(index*2, lo, mid, left, right);
            long long rightSum =  recurseQuery(index*2 + 1, mid+1, hi, left, right);
            return merge(leftSum, rightSum);
        }
    }
};

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


bool checkValid(int start, int end, SegmentTreeMax &maxTree, SegmentTreeMin &minTree, unordered_map<long long, bool, custom_hash> &validBreak) {
    //cout << "CHECKING" << start << " " << end << " ";
    int maxVal = maxTree.query(start, end);
    int minVal = minTree.query(start, end);
    //cout << "MINVAL " << minVal << " MAXVAL" << maxVal << endl;
    if (minVal == start +1 && maxVal == end+1) {
        if (!validBreak[start-1]) {
            validBreak[start-1] = true;
        }
        //cout << "TRUE" << endl;
        return true;
    }
    //cout << "FALSE" <<endl;
    return false;
}

int checkSurroundIntervals(int midSplit, set<int> &breaks, SegmentTreeMax &maxTree, SegmentTreeMin &minTree, unordered_map<long long, bool, custom_hash> &validBreak) {
    auto it = breaks.find(midSplit);
    it--;
    int prevSplit = *it;
    it++;
    it++;
    int afterSplit = *it;
    int total = 0;
    if (checkValid(prevSplit+1, midSplit, maxTree, minTree, validBreak)) {
        total++;
    }
    if (checkValid(midSplit+1, afterSplit, maxTree, minTree, validBreak)) {
        total++;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, Q;
        cin >> N >> Q;
        vector<long long> permutation (N);
        vector<char> swaps (N); 
        for (int i = 0; i < N; i++) {
            cin >> permutation[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> swaps[i];
        }
        set<int> breaks;
        unordered_map<long long, bool, custom_hash> validBreak;
        SegmentTreeMax maxTree (permutation);
        SegmentTreeMin minTree (permutation);
        //cout << "TESTING " << minTree.query(0, 1) << endl;
        for (int i = 0; i < N-1; i++) {
            if (swaps[i] == 'L' && swaps[i+1] == 'R') {
                breaks.insert(i);
            }
        }
        breaks.insert(N-1);
        breaks.insert(-1);
        int prevSplit = -1;
        int validIntervals = 0;
        for (const int &split: breaks) {
            if (split == -1) {
                continue;
            }
            if (checkValid(prevSplit+1, split, maxTree, minTree, validBreak)) {
                validIntervals++;
            }
            prevSplit = split;
        }
        for (int i = 0; i < Q; i++) {
            int input;
            cin >> input;
            input--;
            if (swaps[input] == 'L') {
                if (swaps[input-1] == 'R' && swaps[input+1] == 'R') {
                    breaks.erase(input);
                    if (validBreak[input]) {
                        validBreak[input] = false;
                        validIntervals--;
                    }
                    auto it = breaks.lower_bound(input);
                    int nextSplit = *it;
                    it--;
                    int prevSplit = *it;
                    if (validBreak[prevSplit]) {
                        validBreak[prevSplit] = false;
                        validIntervals--;  
                    }
                    if (checkValid(prevSplit+1, nextSplit, maxTree, minTree, validBreak)) {
                        validIntervals++;
                    }
                } else if (swaps[input-1] == 'L' && swaps[input+1] == 'L') {
                    auto it = breaks.lower_bound(input-1);
                    it--;
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                    }
                    breaks.insert(input-1);
                    validIntervals += checkSurroundIntervals(input-1, breaks, maxTree, minTree, validBreak);  
                } else if (swaps[input-1] == 'L' && swaps[input+1] == 'R') {
                    auto it = breaks.find(input);
                    //cout << "CHECKINGING " << *it << endl;
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                        //cout << "REMOVING " << *it << endl;
                    }
                    it--;
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                        //cout << "REMOVING " << *it << endl;
                    }
                    breaks.erase(input);
                    breaks.insert(input-1);
                    validIntervals += checkSurroundIntervals(input-1, breaks, maxTree, minTree, validBreak);  
                }
                swaps[input] = 'R';
            } else {
                if (swaps[input-1] == 'L' && swaps[input+1] == 'L') {
                    auto it = breaks.find(input-1);
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                    }
                    it--;
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                    }
                    breaks.erase(input-1);
                    it = breaks.lower_bound(input-1);
                    int nextSplit = *it;
                    it--;
                    int prevSplit = *it;
                    if (checkValid(prevSplit+1, nextSplit, maxTree, minTree, validBreak)) {
                        validIntervals++;
                    }
                } else if (swaps[input-1] == 'R' && swaps[input+1] == 'R') {
                    auto it = breaks.lower_bound(input);
                    it--;
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                    }
                    breaks.insert(input);
                    validIntervals += checkSurroundIntervals(input, breaks, maxTree, minTree, validBreak);  
                } else if (swaps[input-1] == 'L' && swaps[input+1] == 'R') {
                    auto it = breaks.find(input-1);
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                    }
                    it--;
                    if (validBreak[*it]) {
                        validIntervals--;
                        validBreak[*it] = false;
                    }
                    breaks.erase(input-1);
                    breaks.insert(input);
                    validIntervals += checkSurroundIntervals(input, breaks, maxTree, minTree, validBreak);  
                }
                swaps[input] = 'L';
            }
            //cout << validIntervals << " " << breaks.size() << " BREAK SIZE "<< endl;
            if (breaks.size() == validIntervals+1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}