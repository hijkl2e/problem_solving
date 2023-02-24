#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(M);
	int sum{};
	for (int i = 0; i <= N; ++i) {
		sum = (sum + A[i]) % M;
		++B[sum];
	}
	ll ans{};
	for (int i = 0; i < M; ++i) {
		ans += B[i] * (B[i] - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}
