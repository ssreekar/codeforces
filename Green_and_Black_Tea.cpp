#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, A, B;
    cin >> N >> K >> A >> B;
    char BigChar = 'G';
    char SmallChar = 'B';
    if (B > A) {
        BigChar = 'B';
        SmallChar = 'G';
    }
    int smallOne = min(A, B);
    int bigOne = max(A, B);
    int insideSpaces = ceil(double(bigOne) / K) - 1;
    if (smallOne < insideSpaces) {
        cout << "NO";
        return 0;
    }
    bool big = true;
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (big) {
            cout << BigChar;
            bigOne--;
            counter++;
            if (counter == K || bigOne == 0) {
                counter = 0;
                big = false;
            }
        } else {
            //cout << counter << " C " << insideSpaces << " D " << smallOne << endl;
            if (counter == 0) {
                insideSpaces--;
            }
            cout << SmallChar;
            counter++;
            smallOne--;
            if (counter == K || insideSpaces == smallOne) {
                counter = 0;
                big = true;
            }
        }
    }

    return 0;
}