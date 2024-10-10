#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<long long> arr (N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        stack<pair<long long, long long> > past;
        past.push({arr[0], 1});
        for (int i = 1; i < N; i++) {
            if (past.top().first < arr[i]) {
                past.push({arr[i], 1});
            } else if (past.top().first == arr[i]) {
                long long count = past.top().second;
                past.pop();
                past.push({arr[i], count+1});
            } else {
                long long totalAmount = arr[i];
                long long totalCount = 1;
                while(!past.empty()) {
                    long long amount = past.top().first;
                    long long count = past.top().second;
                    totalAmount += (amount * count);
                    totalCount += count;
                    past.pop();
                    long long average =  totalAmount / totalCount;
                    long long additionCount = totalAmount % totalCount;
                    long long averageCount = totalCount - additionCount;
                    if (past.empty () || average > past.top().first) {
                        past.push({average, averageCount});
                        if (additionCount > 0) {
                            past.push({average+1, additionCount});
                        }
                        //cout << "Adding " << average << " " << averageCount << endl;
                        //cout << "Adding " << average+1 << " " << additionCount << endl;  
                        break;
                    } else if (average == past.top().first) {
                        long long extraCount = past.top().second;
                        past.pop();
                        past.push({average, averageCount + extraCount});
                        if (additionCount > 0) {
                            past.push({average+1, additionCount});
                        }          
                        //cout << "Adding " << average << " " << averageCount << endl;
                        //cout << "Adding " << average+1 << " " << additionCount << endl; 
                        break;
                    }
                }
            }
        }
        long long maxAmount = past.top().first;
        long long minAmount = past.top().first;
        while(!past.empty()) {
            minAmount = past.top().first;
            past.pop();
        }
        cout << maxAmount - minAmount << '\n';
    }
    return 0;
}