#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll square(ll x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	ll ans{};
	for (int i = 1; i < N; ++i) {
		ans += square(H[i] + H[i - 1]) + square(H[i] - H[i - 1]);
	}
	cout << ans << "\n";
	return 0;
}
