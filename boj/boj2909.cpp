#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, K{};
	cin >> C >> K;
	if (K == 0) {
		cout << C << "\n";
		return 0;
	}
	int x = 1;
	while (K--) {
		x *= 10;
	}
	int ans = C - C % x + (C / (x / 10) % 10 > 4) * x;
	cout << ans << "\n";
	return 0;
}
