#include <iostream>
#include <vector>

using namespace std;

bool test(int size, vector<vector<int> > &diffArr) {
    //cout << " ? " <<  diffArr.size() << endl;
    vector<int> start (20, -1);
    for (int i = 0; i + size < diffArr.size(); i++) {
        //cout << i << endl;
        for (int j = 0; j < 20; j++) {
            int value = diffArr[i + size][j] - diffArr[i][j];
            int binaryVal = value > 0 ? 1 : 0;
            //cout << "value "<< value << endl;
            if (start[j] == -1) {
                start[j] = binaryVal;
            } else if (start[j] != binaryVal) {
                //cout << "Bad Index " << i << " " << j << " " << binaryVal << " " << start[j] << endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N; 
        cin >> N;
        vector<int> arr (N);
        //cout << "Made it" << endl;
        vector<vector<int> > bitArr (N, vector<int> (20, 0));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            int val = arr[i];
            for (int j = 0; j < 20; j++) {
                bitArr[i][j] = arr[i] & (1 << j); 
            }
        }

        //cout << "Made it 2" << endl;
        vector<vector<int> > diffArr (N+1, vector<int> (20, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 20; j++) {
                diffArr[i][j] = diffArr[i-1][j] + bitArr[i-1][j];
                //cout << diffArr[i][j] << " ";
            }
            //cout << endl;
        }

        //cout << "Made it 3" << endl;
        
        int lo = 1;
        int hi = N;
        int lowest = N;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            //cout << "Mid " << mid << endl; 
            bool success = test(mid, diffArr);
            if (success) {
                lowest = min(lowest, mid);
                //cout << "Worked" << endl;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << lowest << endl;
    }
    return 0;
}