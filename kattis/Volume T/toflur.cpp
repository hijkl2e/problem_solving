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
	ll ans{};
	for (int i = 0; i < N - 1; ++i) {
		ans += (A[i] - A[i + 1]) * (A[i] - A[i + 1]);
	}
	cout << ans << "\n";
	return 0;
}
