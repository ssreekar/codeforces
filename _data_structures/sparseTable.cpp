#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Constant Log Method 
int log2_floor(unsigned long long i) {
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
