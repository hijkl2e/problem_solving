#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> x(N);
	vector<int> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	int maxv = -INF, ans{};
	for (int i = 0; i < N; ++i) {
		maxv = max(maxv, x[i]);
		ans += max(maxv, y[i]) - maxv;
		maxv = max(maxv, y[i]);
	}
	cout << ans << "\n";
	return 0;
}
