#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans{};
	while (M--) {
		int x{};
		cin >> x;
		ans += *lower_bound(A.begin(), A.end(), x) - x;
	}
	cout << ans << "\n";
	return 0;
}
