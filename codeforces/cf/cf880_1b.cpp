#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N, M, K;
vector<ll> A;

ll solve(ll x) {
	static int p1, p2;
	while (p1 < N && A[p1] <= x) {
		++p1;
	}
	while (p2 < N && A[p2] < x) {
		++p2;
	}
	if (p1 - p2 >= K) {
		return 0;
	}
	ll l = p1 - K >= 0 ? x - (x - A[p1 - K] - 1) / 2 : 0;
	ll r = p2 + K - 1 < N ? x + (A[p2 + K - 1] - x - 1) / 2 : M;
	return r - l + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<ll> B{0};
	for (int i = 0; i < N; ++i) {
		for (ll j = max(A[i] - 2, B.back() + 1); j <= min(A[i] + 2, M); ++j) {
			B.push_back(j);
		}
	}
	ll ans_x{}, ans_y{};
	for (ll x : B) {
		ll y = solve(x);
		if (ans_y < y) {
			ans_x = x, ans_y = y;
		}
	}
	cout << ans_y << " " << ans_x << "\n";
	return 0;
}
