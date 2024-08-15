#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    int count = 0;
    vector<bool> visited (26, false);
    for (int i = 0; i < input.size(); i++) {
        if (!visited[input[i] - 'a']) {
            count++;
            visited[input[i] - 'a'] = true;
        }
    }
    if (count % 2 == 0) {
        cout << "CHAT WITH HER!\n"; 
    } else {
        cout << "IGNORE HIM!\n";
    }
    return 0;
}