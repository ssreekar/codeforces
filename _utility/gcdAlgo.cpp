#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}