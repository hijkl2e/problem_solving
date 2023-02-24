#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	while (M--) {
		ll q{}, x{}, y{};
		cin >> q >> x;
		int ans{};
		if (q == 1) {
			int p = lower_bound(A.begin(), A.end(), x) - A.begin();
			ans = N - p;
		} else if (q == 2) {
			int p = upper_bound(A.begin(), A.end(), x) - A.begin();
			ans = N - p;
		} else {
			cin >> y;
			int p1 = lower_bound(A.begin(), A.end(), x) - A.begin();
			int p2 = upper_bound(A.begin(), A.end(), y) - A.begin();
			ans = p2 - p1;
		}
		cout << ans << "\n";
	}
	return 0;
}
