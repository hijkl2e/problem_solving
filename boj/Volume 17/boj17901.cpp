#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N;
	map<int, int> prev;
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		auto &y = prev[x];
		if (y) {
			ans = min(ans, i - y);
		}
		y = i;
	}
	cout << ans << "\n";
	return 0;
}
