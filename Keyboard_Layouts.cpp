#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string first;
    string second;
    cin >> first >> second;
    string input;
    cin >> input;
    unordered_map<char, char> mapKeys;

    for (int i = 0; i < first.size(); i++) {
        mapKeys[first[i]] = second[i];
        mapKeys[toupper(first[i])] = toupper(second[i]); 
    }

    for (int i = 0; i < input.size(); i++) {
        if (mapKeys.find(input[i]) != mapKeys.end()) {
            cout << mapKeys[input[i]];
        } else {
            cout << input[i];
        }
        
    }
    return 0;
}