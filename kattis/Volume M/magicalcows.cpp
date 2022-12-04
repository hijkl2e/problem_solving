#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{}, M{};
	cin >> C >> N >> M;
	vector<ll> A(C + 1);
	while (N--) {
		int x{};
		cin >> x;
		++A[x];
	}
	vector<ll> ans(51);
	for (int i = 0; i < ans.size(); ++i) {
		ans[i] = accumulate(A.begin(), A.end(), 0LL);
		for (int j = C; j > 0; --j) {
			if (2 * j <= C) {
				A[2 * j] += A[j];
				A[j] = 0;
			} else {
				A[j] *= 2;
			}
		}
	}
	while (M--) {
		int x{};
		cin >> x;
		cout << ans[x] << "\n";
	}
	return 0;
}
