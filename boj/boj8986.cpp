#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ii> B;
	B.push_back({0, 0});
	for (int i = 1; i < N; ++i) {
		B.push_back({A[i] / i + (A[i] % i > 0), i});
	}
	B.push_back({INF, N});
	sort(B.begin(), B.end());
	ll sum = accumulate(A.begin(), A.end(), 0LL);
	ll X = N * (N - 1LL) / 2;
	ll ans = 4e18;
	for (int i = 0; i < N; ++i) {
		sum -= 2 * A[B[i].second];
		X -= 2 * B[i].second;
		if (B[i].first == B[i + 1].first) {
			continue;
		}
		ll k = X > 0 ? (B[i + 1].first - 1) : B[i].first;
		ll d = sum - k * X;
		ans = min(ans, d);
	}
	cout << ans << "\n";
	return 0;
}
