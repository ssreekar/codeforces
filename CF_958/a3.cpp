#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        unsigned long long N;
        cin >> N;
        vector<unsigned long long> ones;
        unsigned long long value = 1;
        unsigned long long index = 0;
        while(value <= N) {
            if ((N & value) > 0) {
                ones.push_back(index);
            }
            index++;
            value *= 2;
            //cout << value << endl;
        }
        vector<unsigned long long> nums;
        if (ones.size() == 1) {
            nums.push_back(N);
        } else {
            nums.push_back(1ULL << ones[ones.size() - 2]);
            for (int i = ones.size() - 2; i >= 0; i--) {
                unsigned long long currNum = 0;
                for (int j = 0; j < ones.size(); j++) {
                    if (j != i) {
                        currNum |= (1ULL << ones[j]); 
                    }
                }
                nums.push_back(currNum);
            }
            nums.push_back(N);
        }
        cout << nums.size() << '\n';
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}