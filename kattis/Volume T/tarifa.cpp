#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, N{};
	cin >> X >> N;
	int ans = (N + 1) * X;
	while (N--) {
		int P{};
		cin >> P;
		ans -= P;
	}
	cout << ans << "\n";
	return 0;
}
