#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A;
	for (ll i = 1; i < 50001; ++i) {
		if (i * i <= N) {
			continue;
		}
		ll j = sqrt(i * i - N) + EPS;
		if (i * i - N == j * j) {
			A.push_back(i);
		}
	}
	if (A.size()) {
		for (int x : A) {
			cout << x << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
