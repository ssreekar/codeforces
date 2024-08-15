#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int open = 0;
    bool messed = false;
    bool done = false;
    for (int i = 0; i < N; i++) {
        char input;
        cin >> input; 
        if (input == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                if (messed) {done = true;}
                messed = true;
            }
        }
    }
    if (open == 0 && messed) {
        done = true;
    }
    if (open > 1) {
        done = true;
    }
    if (open == 1 && !messed) {
        done = true;
    }
    if (done) {
        cout << "No" << endl; 
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}