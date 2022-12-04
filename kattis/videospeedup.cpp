#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	double K{};
	cin >> N >> P >> K;
	double ans{};
	int prev{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		ans += (x - prev) * (1 + i * P / 100.0);
		prev = x;
	}
	ans += (K - prev) * (1 + N * P / 100.0);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
