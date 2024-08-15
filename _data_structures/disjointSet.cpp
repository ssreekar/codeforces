#include <vector>
#include <iostream>

using namespace std;

struct disjointSet {

    vector<int> parent;
    vector<int> sizes;

    disjointSet(int size) {
        parent.resize(size);
        sizes.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int findSet(int value) {
        if (value < 0 || value >= parent.size()) {
            cout << "Not a set" << endl;
            return -1;
        }
        vector<int> order = {value};
        while(parent[value] != value) {
            value = parent[value];
            order.push_back(value);
        }
        for (int i = 0; i < order.size(); i++) {
            parent[order[i]] = value;
        }
        return value;
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == -1 || b == -1) {
            cout << "Cant merge" << endl;
            return;
        }
        if (a != b) {
            if (sizes[a] < sizes[b]) {
                swap(a, b);
            }
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};