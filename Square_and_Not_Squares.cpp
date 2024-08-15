#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<long long> arr(N);
    vector<pair<long long, long long> > disToSquare(N);
    vector<pair<long long, long long> > disToNonSquare(N);
    long long nonSquares = 0;
    long long squares = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        long long lowerVal = sqrt(arr[i]);
        long long upperVal = lowerVal + 1;
        long long lowerDiff = abs((lowerVal * lowerVal) - arr[i]);
        long long upperDiff = abs((upperVal * upperVal) - arr[i]);
        disToSquare[i] = {min(lowerDiff, upperDiff), i};
        //cout << disToSquare[i].first << " " << disToSquare[i].second << endl;
        long long nonSquare = 0;
        if (min(lowerDiff, upperDiff) == 0) {
            nonSquare = 1;
            squares++;
        } else {
            nonSquares++;
        }
        if (arr[i] == 0) {
            nonSquare = 2;
        }
        disToNonSquare[i] = {nonSquare, i};
    }

    //cout << squares << " " << nonSquares << endl;
    if (squares == nonSquares) {
        cout << 0 << endl;
    } else if (squares > nonSquares) {
        int diff = (squares - nonSquares) / 2;
        long long total = 0;
        sort(disToNonSquare.begin(), disToNonSquare.end());
        for (int i = 0; i < diff + nonSquares; i++) {
            total += disToNonSquare[i].first;
        }
        cout << total << endl;
    } else {
        int diff = (nonSquares - squares) / 2;
        long long total = 0;
        sort(disToSquare.begin(), disToSquare.end());
        for (int i = 0; i < diff + squares; i++) {
            total += disToSquare[i].first;
        }
        cout << total << endl;
    }


    return 0;
}