#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    string input;
    cin >> input;
    long long X = 0;
    long long Y = 0;
    vector<vector<long long> > testPoints;
    testPoints.push_back({a,b});
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'U') {
            Y++;
            b--;
        } else if (input[i] == 'D') {
            Y--;
            b++;
        }
        else if (input[i] == 'L') {
            X--;
            a++;
        } else if (input[i] == 'R') {
            X++;
            a--;
        }
        testPoints.push_back({a,b});
    }

    bool valid = false;

    for (int i = 0; i < testPoints.size(); i++) {
        long long testA = testPoints[i][0];
        long long testB = testPoints[i][1];
        long long tempX = X;
        long long tempY = Y;
        if (tempX < 0) {
            if (testA > 0) {
                continue;
            } else {
                tempX = abs(tempX);
                testA = abs(testA);
            }
        } 
        if (testA < 0) {
            continue;
        }
        if (tempY < 0) {
            if (testB > 0) {
                continue;
            } else {
                tempY = abs(tempY);
                testB = abs(testB);
            }
        }
        if (testB < 0) {
            continue;
        }

        long long aVal = -1;
        long long bVal = -1;
        bool special = false;
        if (tempX == 0) {
            if (testA == 0) {
                aVal = 0;
                special = true;
            } else {
                continue;
            }
        } else if (testA % tempX == 0) {
            aVal = testA / tempX;
        }
        if (tempY == 0) {
            if (testB == 0) {
                bVal = 0;
                special = true;
            } else {
                continue;
            }
        } else if (testB % tempY == 0) {
            bVal = testB / tempY;
        }
        if (aVal != -1 && bVal != -1) {
            if (aVal == bVal || special) {
                valid = true;
            }

        }
    }
    if (valid) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}