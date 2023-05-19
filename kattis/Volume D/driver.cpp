#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> C(N);
	for (int i = 1; i < N; ++i) {
		cin >> C[i];
	}
	vector<int> T(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i];
	}
	int t{}, minv = 1e9;
	ll ans = accumulate(C.begin(), C.end(), 0LL);
	for (int i = 1; i < N; ++i) {
		minv = min(minv, C[i]);
		ll x = max(T[i] - t, 0) / 2 * 2;
		t += x + 1;
		ans += x * minv;
	}
	cout << ans << "\n";
	return 0;
}
