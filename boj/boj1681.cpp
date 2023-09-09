#include <bits/stdc++.h>

using namespace std;

bool solve(int x, int L) {
	while (x) {
		if (x % 10 == L) {
			return true;
		}
		x /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	int ans{};
	for (int i = 0, j = 1; i < N; ++i, ++j) {
		while (solve(j, L)) {
			++j;
		}
		ans = j;
	}
	cout << ans << "\n";
	return 0;
}
