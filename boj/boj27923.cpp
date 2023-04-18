#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, L{};
	cin >> N >> K >> L;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	while (K--) {
		int x{};
		cin >> x;
		++B[x];
		if (x + L <= N) {
			--B[x + L];
		}
	}
	partial_sum(B.begin(), B.end(), B.begin());
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += A[i] >> min(B[i], 30);
	}
	cout << ans << "\n";
	return 0;
}
