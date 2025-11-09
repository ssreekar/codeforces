#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

ll solve(vll &arr) {
	unordered_map<ll, ll> value;
	ll total = 0;
	ll sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		ll diff = sum - (i+1);
		if (!diff) {
			total += 1;
		}
		total += value[diff];
		value[diff]++;
	}
	return total;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N;
		cin >> N;
        vll arr(N);
		for (int i = 0; i < N; i++) {
			char input;
			cin >> input;
			arr[i] = input - '0';
		}
		cout << solve(arr) << '\n';
	}
    

	return 0;
}

