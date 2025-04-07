#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (auto &[x, y] : A) {
		cin >> x >> y;
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int k = 0; k < 2; ++k) {
		int maxv = A[0].second - A[0].first;
		for (int i = 1; i < N; ++i) {
			int val = A[i].second - A[i].first;
			ans = max(ans, maxv - val);
			maxv = max(maxv, val);
		}
		if (k == 0) {
			for (auto &[x, y] : A) {
				y *= -1;
				swap(x, y);
			}
			sort(A.begin(), A.end());
		}
	}
	cout << ans << "\n";
	return 0;
}
