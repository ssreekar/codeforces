#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    char input;
    int index = (N-1) / 2;
    int offset = 0;
    bool right = (N % 2);
    vector<char> value (N);
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (!right) {
            value[index - offset] = input;
            right = true;
            if (N % 2 == 0) {offset++;}
        } else {
            value[index + offset] = input;
            right = false;
            if (N % 2) {offset++;}
        }    
    }
    for (int i = 0; i < N; i++) {
        cout << value[i];
    }
    return 0;
}