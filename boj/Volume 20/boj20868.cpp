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
	int idx = find(A.begin(), A.end(), 0) - A.begin();
	ll sum{}, maxv{}, minv{};
	for (int i = idx - 1; i >= 0; --i) {
		sum += A[i];
		maxv = max(maxv, sum);
	}
	sum = 0;
	for (int i = idx + 1; i < A.size(); ++i) {
		sum += A[i];
		minv = min(minv, sum);
	}
	ll ans{};
	for (int i = 0; i < A.size(); ++i) {
		ans += (i + 1) * A[i];
	}
	ans += max(maxv, -minv);
	cout << ans << "\n";
	return 0;
}
