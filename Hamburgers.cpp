// https://codeforces.com/problemset/problem/371/C
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string recipe;
    cin >> recipe;
    ll totalB = 0;
    ll totalS = 0;
    ll totalC = 0;
    for (int i = 0; i < recipe.size(); i++) {
        if (recipe[i] == 'B') {
            totalB++;
        } else if (recipe[i] == 'S'){
            totalS++;
        } else {
            totalC++;
        }
    }
    ll currB;
    ll currS;
    ll currC;

    cin >> currB >> currS >> currC;

    ll priceB;
    ll priceS;
    ll priceC;
    cin >> priceB >> priceS >> priceC;

    ll rubles;
    cin >> rubles;

    ll lo = 0;
    ll hi = 1e14;
    ll bestValid = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        //cout << mid << endl;
        ll currRubles = rubles;
        ll diffB = max(ll(0), (mid * totalB) - currB);
        ll diffS = max(ll(0), (mid * totalS) - currS);
        ll diffC = max(ll(0), (mid * totalC) - currC);
        currRubles -= priceB * diffB;
        currRubles -= priceS * diffS;
        currRubles -= priceC * diffC;
        if (currRubles < 0) {
            hi = mid-1;
        } else {
            bestValid = mid;
            lo = mid + 1;
        }
    }
    cout << bestValid << endl;
	return 0;
}

