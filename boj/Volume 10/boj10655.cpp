#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

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
	int sum{};
	for (int i = 0; i < N - 1; ++i) {
		sum += dist(x[i], y[i], x[i + 1], y[i + 1]);
	}
	int ans = sum;
	for (int i = 1; i < N - 1; ++i) {
		ans = min(ans, sum - dist(x[i - 1], y[i - 1], x[i], y[i])
					- dist(x[i], y[i], x[i + 1], y[i + 1])
					+ dist(x[i - 1], y[i - 1], x[i + 1], y[i + 1]));
	}
	cout << ans << "\n";
	return 0;
}
