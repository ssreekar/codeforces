#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

long long getSum(int num, vector<long long> &prefixSum, vector<int> &primes) {
    int lo = 0;
    int hi = primes.size()-1;
    int lowestValid = 0;
    while(lo <= hi) {
        int mid = (lo+hi) / 2;
        if (primes[mid] <= num) {
            lo = mid + 1;
            lowestValid = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return prefixSum[lowestValid];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr (N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vector<int> primes;
    for (int i = 2; i <= 3200; i++) {
        bool notPrime = false;
        for (int j = 2; j < min(sqrt(i) + 1, double(i)); j++) {
            if (i % j == 0) {
                notPrime = true;
                break;
            }
        }
        if (!notPrime) {
            primes.push_back(i);
        }
    }

    vector<int> primeCount (primes.size(), 0);
    map<int, int> extraPrimes;

    for (int i = 0; i < N; i++) {
        int value = arr[i];
        for (int j = 0; j < primes.size(); j++) {
            if (value % primes[j] == 0) {
                primeCount[j]++;
                while(value % primes[j] == 0) {
                    value /= primes[j];
                }
            }
        }

        if (value > 1) {
            extraPrimes[value]++;
        }
    }

    for (auto it = extraPrimes.begin(); it != extraPrimes.end(); it++) {
        primes.push_back(it->first);
        primeCount.push_back(it->second);
    }
    
    vector<long long> prefixSum (primeCount.size() + 1, 0);
    for (int i = 1; i < prefixSum.size(); i++) {
        prefixSum[i] = primeCount[i-1] + prefixSum[i-1];
    }


    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        cout << getSum(R, prefixSum, primes) - getSum(L-1, prefixSum, primes) << '\n';
    }

    return 0;
}