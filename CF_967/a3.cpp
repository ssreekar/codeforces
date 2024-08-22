#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<pair<int, int> > edges;
        for (int i = 2; i <= N; i++) {
            int testVal = 1;
            while(true) {
                cout << "? " << i << " " << testVal << endl;
                int input;
                cin >> input;
                if (input == i) {
                    edges.push_back({testVal, i});
                    break;
                } else if (input == -1) {
                    return 0;
                }
                testVal = input;
            }
        }
        cout << "! ";
        for (int i = 0; i < edges.size(); i++) {
            cout << edges[i].first << " " << edges[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}