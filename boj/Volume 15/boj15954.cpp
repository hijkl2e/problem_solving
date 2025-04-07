#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	double ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ll s1{}, s2{};
		for (int j = i; j < N; ++j) {
			s1 += A[j];
			s2 += A[j] * A[j];
			int cnt = j - i + 1;
			if (cnt >= K) {
				ans = min(ans, sqrt((s2 * cnt - s1 * s1) * 1.0 / (cnt * cnt)));
			}
		}
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
