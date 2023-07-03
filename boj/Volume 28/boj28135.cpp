#include <bits/stdc++.h>

using namespace std;

bool solve(int x) {
	while (x) {
		if (x % 100 == 50) {
			return true;
		}
		x /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 1;
	for (int i = 1; i < N; ++i) {
		ans += solve(i) ? 2 : 1;
	}
	cout << ans << "\n";
	return 0;
}
