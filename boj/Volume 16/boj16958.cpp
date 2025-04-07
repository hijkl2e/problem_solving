#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> s(N);
	vector<int> x(N);
	vector<int> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> s[i] >> x[i] >> y[i];
	}
	vector<int> z(N, 1e9);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (s[j]) {
				z[i] = min(z[i], dist(x[i], y[i], x[j], y[j]));
			}
		}
	}
	int M{};
	cin >> M;
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		--a, --b;
		int ans = min(dist(x[a], y[a], x[b], y[b]), z[a] + T + z[b]);
		cout << ans << "\n";
	}
	return 0;
}
