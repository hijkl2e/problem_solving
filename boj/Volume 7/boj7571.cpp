#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> x(M);
	vector<int> y(M);
	for (int i = 0; i < M; ++i) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int ans{};
	for (int i = 0; i < M; ++i) {
		ans += abs(x[M / 2] - x[i]) + abs(y[M / 2] - y[i]);
	}
	cout << ans << "\n";
	return 0;
}
