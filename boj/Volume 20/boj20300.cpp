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
	sort(A.begin(), A.end());
	ll ans = N % 2 ? A[N - 1] : 0;
	for (int i = 0, j = N - N % 2 - 1; i < j; ++i, --j) {
		ans = max(ans, A[i] + A[j]);
	}
	cout << ans << "\n";
	return 0;
}
