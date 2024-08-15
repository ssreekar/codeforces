#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<long long> A (N);
    vector<long long> B (N);
    vector<pair<long long, long long> > diff (N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        diff[i] = {B[i] - A[i], i};
    }
    sort(diff.begin(), diff.end());
    long long total = 0;
    for (int i = 0; i < N; i++) {
        long long index = diff[i].second;
        total += (A[index] * i) + (B[index] * (N - i - 1));
    }
    cout << total << endl;
    return 0;
}