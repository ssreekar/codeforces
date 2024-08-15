#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

// Constant Log Method 
int log2_floor(unsigned int i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}


// Sparse Table
struct sparseTable {

    // CHANGE SIZE BASED ON PROBLEM
    const static int SIZE_N = 1e5 + 10;

    int KMAX = 25;
    int table[26][SIZE_N];

    int sparseFunction(int a, int b) {
        // CHANGE THIS TO CHANGE SPARSE TABLE TYPE
        return std::gcd(a, b);
    }

    sparseTable(vector<int> &arr) {

        for (int i = 0; i < arr.size(); i++) {
            table[0][i] = arr[i];
        }

        for (int i = 1; i <= KMAX; i++) {
            for (int j = 0; j + (1 << i) <= arr.size() ; j++) {
                table[i][j] = sparseFunction(table[i-1][j], table[i-1][j + (1 << (i-1))]);
            }
        }
    }

    int rangeAssociative(int a, int b) {
        int sum = 0;
        for (int i = KMAX; i >= 0; i--) {
            if (1 << i <= b - a + 1) {
                sum = sparseFunction(sum, table[i][a]);
                a += 1 << i;
            }
        }
        return sum;
    }

    int rangeIdempotent(int a, int b) {
        int val = 0;
        int i = log2_floor(b - a + 1);
        return sparseFunction(table[i][a], table[i][b - (1 << i) + 1]);
    }

};

int main() {
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int N;
    cin >> N;
    vector<int> arr (N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int Q;
    cin >> Q;

    unordered_map<int, long long> finalMap;
    unordered_map<int, long long> gcdList;
    for (int i = 0; i < N; i++) {
        unordered_map<int, long long> newGcdList;
        newGcdList[arr[i]] = 1;
        finalMap[arr[i]]++;
        for (auto it = gcdList.begin(); it != gcdList.end();  it++) {
            int newGCD = gcd(it->first, arr[i]);
            newGcdList[newGCD] += it->second;
            finalMap[newGCD] += it->second;
        }
        gcdList = newGcdList;
    }
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        cout << finalMap[query] << '\n';
    }


    return 0;
}