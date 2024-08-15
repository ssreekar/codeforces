#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    stringstream stream(input);
    string segment;
    vector<string> words;

    while (getline(stream, segment, ',')) {
        words.push_back(segment);
    }

    return 0;
}