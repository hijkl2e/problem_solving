#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int p1 = N - 1, p2{};
	ll ans{};
	for (int i = 0; i < N; ++i) {
		while (p1 && A[N - 1] - A[i] <= A[p1]) {
			--p1;
		}
		while (p2 < N && A[N - 1] + A[i] >= 2 * A[p2]) {
			++p2;
		}
		ans += max(p1 - p2 + 1, 0);
	}
	cout << ans << "\n";
	return 0;
}
