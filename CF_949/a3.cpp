#include <iostream>
#include <vector>

using namespace std;

// Constant Log Method 
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N;
        cin >> N;
        vector<long long> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int nextI = -1;
        bool done = false;
        for (int i = N-1; i >= 0; i--) {
            if (arr[i] != -1) {
                if (nextI == -1) {
                    for (int j = i+1; j < N; j++) {
                        arr[j] = arr[j-1] == 1 ? 2 : arr[j-1] / 2;
                    }
                } else {
                    int diff = nextI - i;
                    if (arr[nextI] <= arr[i]) {
                        long long tempVal = arr[i];
                        int oscIndex = -1;
                        for (int j = 0; j <= diff; j++) {
                            if (tempVal == arr[nextI]) {
                                if ((diff - j) % 2 == 0) {
                                    oscIndex = j + i;
                                    break;
                                } else {
                                    done = true;
                                    break;
                                }
                            }
                            tempVal /= 2;
                        }
                        if (oscIndex == -1 || done == true) {
                            done = true;
                            break;
                        }
                        for (int j = i+1; j < nextI; j++) {
                            if (j > oscIndex) {
                                arr[j] = (oscIndex-j) % 2 != 0 ? arr[j-1] * 2: arr[j-1] / 2; 
                            } else {
                                arr[j] = arr[j-1] / 2;
                            }
                        }
                    } else {
                        long long tempLo = arr[i];
                        long long tempHi = arr[i];
                        long long binaryDiff = -1;
                        long long oscIndex = -1;
                        long long bitIndex = 0;
                        long long arrDiff = log2_floor(arr[nextI] / arr[i]);
                        if (arrDiff < diff) {
                            
                        } 
                        for (int j = 0; j <= diff; j++) {
                            if (tempLo <= arr[nextI] && tempHi >= arr[nextI]) {
                                if ((diff - j) % 2 == 0) {
                                    oscIndex = j + i;
                                    binaryDiff = arr[nextI] - tempLo;
                                } else {
                                    done = true;
                                }
                                break;
                            }
                            bitIndex++;
                            tempLo *= 2;
                            tempHi = (tempHi * 2) + 1;
                        }
                        if (oscIndex == -1 || done == true) {
                            done = true;
                            break;
                        }
                        bitIndex--;
                        for (int j = i+1; j < nextI; j++) {
                            if (j > oscIndex) {
                                arr[j] = (oscIndex-j) % 2 != 0 ? arr[j-1] * 2: arr[j-1] / 2; 
                            } else {
                                if (binaryDiff & (1 << bitIndex)) {
                                    arr[j] = (arr[j-1] * 2) + 1;
                                } else {
                                    arr[j] = arr[j-1] * 2;
                                }
                            }
                        }
                    }
                }
                nextI = i;
            }
        }
        if (done) {
            cout << -1 << endl;
            continue;
        }
        if (nextI == -1) {
            for (int i = 0; i <N; i++) {
                int val = i % 2 != 0 ? 1 : 2;
                cout << val << " "; 
            }
            cout << endl;
            continue;
        }
        for (int i = nextI-1; i >= 0; i--) {
            arr[i] = (nextI-i) % 2 != 0 ? arr[i+1] * 2 : arr[i+1] / 2; 
        }
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}