#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, N{};
	cin >> R >> C >> N;
	vector<int> x(N + 1);
	vector<int> y(N + 1);
	vector<int> z(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> z[i] >> x[i];
		y[i] = z[i] == 1 ? 0 : z[i] == 2 ? C : x[i];
		x[i] = z[i] == 3 ? 0 : z[i] == 4 ? R : x[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (z[N] + z[i] == 3) {
			ans += C + min(x[N] + x[i], 2 * R - x[N] - x[i]);
		} else if (z[N] + z[i] == 7) {
			ans += R + min(y[N] + y[i], 2 * C - y[N] - y[i]);
		} else {
			ans += abs(x[N] - x[i]) + abs(y[N] - y[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}
