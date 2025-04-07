#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, w{};
	cin >> N >> w;
	vector<int> deg(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		++deg[u], ++deg[v];
	}
	int cnt{};
	for (int i = 2; i <= N; ++i) {
		if (deg[i] == 1) {
			++cnt;
		}
	}
	double ans = w * 1.0 / cnt;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
