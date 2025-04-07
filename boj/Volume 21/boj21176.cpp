#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, R{};
	cin >> K >> R;
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	int ans{};
	while (R--) {
		int minv = 1e9;
		for (int i = 0; i < K; ++i) {
			int x{};
			cin >> x;
			minv = min(minv, x ? A[i] / x : minv);
		}
		int p{};
		cin >> p;
		ans = max(ans, minv * p);
	}
	cout << ans << "\n";
	return 0;
}
