#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool findTrie(vector<vector<int> > &trie, string &input) {
    int index = 0;
    for (int i = 0; i < input.size(); i++) {
        char letter = input[i];
        if (trie[index][letter - 'a'] == -1) {
            return false;
        }
        index = trie[index][letter - 'a'];
    }
    return true;
}

int insertTrie(vector<vector<int> > &trie, string &input, vector<bool> &accept, int K) {
    int total = 0;
    for (int i = 0; i < input.size(); i++) {
        int index = 0;
        int unacceptable = 0;
        for (int j = i; j < input.size(); j++) {
            char letter = input[j];
            if (!accept[letter - 'a']) {
                unacceptable++;
            }
            if (unacceptable > K) {
                break;
            } else if (trie[index][letter - 'a'] != -1) {
                index = trie[index][letter - 'a'];
            } else {
                vector<int> newInput (26, -1);
                int newIndex = trie.size();
                trie.push_back(newInput);
                trie[index][letter - 'a'] = newIndex;
                total++;
                index = newIndex;
            }
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    string acceptString;
    cin >> input;
    cin >> acceptString;
    int K;
    cin >> K;
    vector<bool> accept (26, false);
    for (int i = 0; i < acceptString.size(); i++) {
        if (acceptString[i] == '1') {
            accept[i] = true;
        }
    }

    vector<vector<int> > trie (1, vector<int> (26, -1));
    
    cout << insertTrie(trie, input, accept, K) << '\n';
    return 0;
}