#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int a, b;
};

// Custom Comparator Function (Edit for use case)
bool cmp(const Edge &a, const Edge &b) {
    return a.a < b.a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Edge> edges;
    sort(edges.begin(), edges.end(), cmp); // Using custom comparator
    return 0;
}