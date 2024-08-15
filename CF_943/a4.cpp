#include <iostream>
#include <vector>

using namespace std;

long long getScore (vector<int> &perm, vector<int> &arr, int N, int K, int pos) {
    vector<bool> visited (N + 1, false);
    long long curScore = 0;
    long long curRound = 0;
    long long maxScore = 0;
    while(visited[pos] == false && curRound < K) {
        visited[pos] = true;
        int roundScore = arr[pos-1];
        curScore += roundScore;
        //cout << "Round " << curRound << " " << curScore << " " << maxScore << '\n';
        curRound++;
        pos = perm[pos-1];
        maxScore = max(maxScore, curScore + ((K - curRound) * roundScore) );
    }
    return maxScore;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, K, PB, PS;
        cin >> N >> K >> PB >> PS;
        vector<int> perm (N);
        vector<int> arr (N);
        for (int i = 0; i < N; i++) {
            cin >> perm[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        long long PBScore = getScore(perm, arr, N, K, PB);
        long long PSScore = getScore(perm, arr, N, K, PS);
        //cout << PBScore << " - " << PSScore << "\n";
        if (PBScore > PSScore) {
            cout << "Bodya\n";
        } else if (PSScore > PBScore) {
            cout << "Sasha\n";
        } else {
            cout << "Draw\n";
        }

    }
    return 0;
}