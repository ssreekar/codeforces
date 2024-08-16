#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        string first, second;
        cin >> first >> second;
        first += 'x';
        second += 'x';
        first.insert(first.begin(), 'x');
        second.insert(second.begin(), 'x');
        long long count = 0;
        for (int i = 1; i + 1 < first.size(); i++) {
            if (first[i-1] == '.' && first[i+1] == '.' && first[i] == '.' && 
                second[i-1] == 'x' && second[i] == '.' && second[i+1] == 'x') {
                count++;
            }
            if (first[i-1] == 'x' && first[i+1] == 'x' && first[i] == '.' && 
                second[i-1] == '.' && second[i] == '.' && second[i+1] == '.') {
                count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}