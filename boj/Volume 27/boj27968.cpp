#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	while (N--) {
		ll x{};
		cin >> x;
		if (A[M - 1] < x) {
			cout << "Go away!\n";
			continue;
		}
		int ans = lower_bound(A.begin(), A.end(), x) - A.begin() + 1;
		cout << ans << "\n";
	}
	return 0;
}
