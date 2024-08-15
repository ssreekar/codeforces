#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < N; i++) {
        char input;
        cin >> input;
        if (input == 'z') {
            zeros++;
        } 
        if (input == 'n') {
            ones++;
        }
    }
    for (int i = 0; i < ones; i++) {
        cout << "1 ";
    }
    for (int i = 0; i < zeros; i++) {
        cout << "0 ";
    }

    return 0;
}