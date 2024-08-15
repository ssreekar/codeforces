#include <iostream>
#include <vector>
#include <unordered_set>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    disjointSet dj (N+1);
    int count = 0;
    //cout << "Skibidi" << endl;
    vector<pair<int, int> > badPairs;
    for (int i = 0; i + 1 < N; i++) {
        int A, B;
        cin >> A >> B;
        if (dj.findSet(A) == dj.findSet(B)) {
            count ++;
            badPairs.push_back({A, B});
        } else {
            dj.unionSet(A, B);
        }
    }

    unordered_set<int> setHeads;
    for (int i = 0; i < N; i++) {
        int top = dj.findSet(i+1);
        setHeads.insert(top);
    }
    cout << count << endl;
    int prevHead = -1;
    int index = 0;
    for (auto it = setHeads.begin(); it != setHeads.end(); it++){
        int head = *it;
        if (prevHead != -1) {
            cout << badPairs[index].first << " " << badPairs[index].second << " " << prevHead << " " << head << endl;
            index++;
        }
        prevHead = head;
    }

    return 0;
}