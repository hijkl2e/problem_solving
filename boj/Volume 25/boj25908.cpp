#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
	int ret{};
	for (int i = 1; i <= x;) {
		int j = x / (x / i);
		if ((j - i) % 2 == 0) {
			ret += x / i * (i % 2 ? -1 : 1);
		}
		i = j + 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, T{};
	cin >> S >> T;
	int ans = solve(T) - solve(S - 1);
	cout << ans << "\n";
	return 0;
}
