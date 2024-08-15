#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

pair<int, int> split (int a, int b) {
    if (a % 2 == 0 && b % 2 == 0) {
        return {a / 2, b / 2};
    } 
    if ((a % 2 == 1 && b % 2 == 0) 
        || (a % 2 == 0 && b % 2 == 1)) {
        return {-1, -1};
    }
    a-= 1;
    b -= 1;
    if (a == 0 &&  b == 0) {
        return {-2, -2};
    }
    return {(a / 2) + 1, (b / 2) + 1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        int North = 0;
        int South = 0;
        int East = 0;
        int West = 0;
        vector<char> directions (N);
        for (int i = 0; i < N; i++) {
            char dir;
            cin >> dir;
            directions[i] = dir;
            if (dir == 'N') {
                North++;
            } else if (dir == 'S') {
                South++;
            } else if (dir == 'E'){ 
                East++;
            } else {
                West++;
            }
        }
        pair<int, int> NS = split(North, South);
        pair<int, int> EW = split(East, West);
        if (NS.first == -1 || EW.first == -1) {
            cout << "NO\n";
            continue;
        }
        if (NS.first == -2 && NS.second == -2) {
            NS.first = 1;
            NS.second = 1;
            if (EW.first == -2 && EW.second == -2) {
                EW.first = 0;
                EW.second = 0;
            } else if (EW.first == 0 && EW.second == 0) {
                cout << "NO\n";
                continue;
            }
        }
        if (NS.first == 0 && NS.second == 0 && EW.first == -2 && EW.second == -2) {
            cout << "NO\n";
            continue;
        }
        if (EW.first == -2 && EW.second == -2) {
            EW.first = 1;
            EW.second = 1;
        }
        for (int i = 0; i < N; i++) {
            if (directions[i] == 'N') {
                if (NS.first > 0) {
                    NS.first -= 1;
                    cout << "R";
                } else {
                    cout << "H";
                }
            } else if (directions[i] == 'S') {
                if (NS.second > 0) {
                    NS.second--;
                    cout << "R";
                } else {
                    cout << "H";
                }
            } else if (directions[i] == 'E') {
                if (EW.first > 0) {
                    EW.first -= 1;
                    cout << "R";
                } else {
                    cout << "H";
                }
            } else if (directions[i] == 'W') {
                if (EW.second > 0) {
                    EW.second--;
                    cout << "R";
                } else {
                    cout << "H";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}