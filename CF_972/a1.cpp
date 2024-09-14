#include <iostream>
#include <vector>

using namespace std;

void add (int base, int &extra, string &output, char val) {
    for (int i = 0; i < base; i++) {
        output += val;
    }
    if (extra > 0) {
        extra--;
        output += val;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        int base = N / 5;
        int extra = N % 5;
        string output = "";
        add(base, extra, output, 'a');
        add(base, extra, output, 'e');
        add(base, extra, output, 'i');
        add(base, extra, output, 'o');
        add(base, extra, output, 'u');
        cout << output  << '\n';
    }
    return 0;
}