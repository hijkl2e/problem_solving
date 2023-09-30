#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	T *= T;
	int ans = T / 4 + T / 2 % 2;
	cout << ans << "\n";
	return 0;
}
