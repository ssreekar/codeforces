#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
    vector<string> arr;
    vector<string> lazyTree;
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
    SegmentTree (string &input) {
        N = input.size();
        arr.resize(N * 4, "");
        lazyTree.resize(N * 4, "");
        build(input, 1, 0, N - 1);
    }

    // Important Functions

    // Query (Max, Min, Sum) from range left to right
    string query(int left, int right) {
        return recurseQuery(1, 0, N-1, left, right);
    }

    // Increment a[left...right] by x
    void update(int left, int right, string x) {
        recurseUpdate(1, 0, N-1, left, right, x);
    }

    // Merge function (Determines Segment Tree Type)
    string merge(string a, string b) {
        int aPtr = 0;
        int bPtr = 0;
        string newVal = "";
        while(aPtr < a.size() || bPtr < b.size()) {
            char aVal = aPtr < a.size() ? a[aPtr] : '{';
            char bVal = bPtr < b.size() ? b[bPtr] : '{';
            if (aVal < bVal) {
                if (newVal.back() != aVal) {
                    newVal += aVal;
                }
                aPtr++;
            } else {
                if (newVal.back() != bVal) {
                    newVal += bVal;
                } 
                bPtr++;
            }
        }
        return newVal;
    }

    // Utility Functions
    void push(int index, int lo, int hi) {
        if (lazyTree[index].size() != 0) {
            lazyUpdate(index, lo, hi, lazyTree[index]);
            lazyTree[index] = "";
        }
    }

    void lazyUpdate(int index, int lo, int hi, string x) {
        arr[index] = x;
        if (lo != hi) {
            lazyTree[index*2] =  merge(x, lazyTree[index*2]);
            lazyTree[index*2+1] = merge(x, lazyTree[index*2+1]);
        }
    }


    void build(string &input, int index, int lo, int hi) {
        if (lo == hi) {
            arr[index] = input[lo];
            //cout << index << " " <<  lo  << " " << hi << " " << arr[index] << endl;
        } else {
            int mid = (hi + lo) / 2;
            build(input, index*2, lo, mid);
            build(input, index*2+1, mid+1, hi);
            arr[index] = merge(arr[index*2], arr[index*2+1]);
            //cout << index << " " <<  lo  << " " << hi << " " << arr[index] << endl;
        }
    }

    string recurseQuery(int index, int lo, int hi, int left, int right) {
        push(index, lo, hi);
        if (left <= lo && right >= hi) {
            return arr[index];
        } else if (left > hi || right < lo) {
            return "";
        } else {
            int mid = (hi + lo) / 2;
            string leftSum = recurseQuery(index*2, lo, mid, left, right);
            string rightSum =  recurseQuery(index*2 + 1, mid+1, hi, left, right);
            return merge(leftSum, rightSum);
        }
    }

    void recurseUpdate(int index, int lo, int hi, int left, int right, string x) {
        push(index, lo, hi);
        if (left <= lo && right >= hi) {
            lazyUpdate(index, lo, hi, x);
            //cout << index << " " <<  lo  << " " << hi << " " << arr[index] << endl;
        } else if (left > hi || right < lo) {
            return;
        } else {
            int mid = (hi + lo) / 2;
            recurseUpdate(index*2, lo, mid, left, right, x);
            recurseUpdate(index*2+1, mid+1, hi, left, right, x);
            arr[index] = merge(arr[index*2], arr[index*2+1]);
            //cout << index << " " <<  lo  << " " << hi << " " << arr[index] << " " << arr[index*2] << " " << arr[index*2+1] << endl;
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    int q;
    cin >> q;
    SegmentTree tree (input);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            string replacement;
            cin >> pos >> replacement;
            tree.update(pos-1, pos-1, replacement);
        } else {
            int l, r;
            cin >> l >> r;
            string output = tree.query(l-1, r-1);
            //cout << output << endl;
            cout << output.size() << '\n';
        }
    }
    return 0;
}