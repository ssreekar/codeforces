#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string input;
    cin >> input;
    int total = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<') {
            total++;
        } else {
            break;
        }
    }
    for (int i = input.size()-1; i>= 0; i--) {
        if (input[i] == '>') {
            total++;
        } else {
            break;
        }
    }
    cout << total << '\n';
    return 0;
}