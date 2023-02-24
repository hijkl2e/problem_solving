#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using query = tuple<int, int, int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<query> B(M - 1);
	for (auto &[i1, j1, i2, j2, k] : B) {
		int q{};
		cin >> q >> i1 >> j1 >> i2 >> j2 >> k;
	}
	int q{}, x1{}, y1{}, x2{}, y2{};
	cin >> q >> x1 >> y1 >> x2 >> y2;
	ll ans{};
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			ans += A[i][j];
		}
	}
	for (auto &[i1, j1, i2, j2, k] : B) {
		i1 = max(i1, x1);
		j1 = max(j1, y1);
		i2 = min(i2, x2);
		j2 = min(j2, y2);
		ans += 1LL * max(i2 - i1 + 1, 0) * max(j2 - j1 + 1, 0) * k;
	}
	cout << ans << "\n";
	return 0;
}
