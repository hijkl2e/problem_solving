#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int maxs = -1, mine = 1e5;
	while (N--) {
		int s{}, e{};
		cin >> s >> e;
		maxs = max(maxs, s);
		mine = min(mine, e);
	}
	int ans = max(maxs - mine, 0);
	cout << ans << "\n";
	return 0;
}
