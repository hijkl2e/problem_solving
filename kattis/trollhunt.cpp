#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int B{}, K{}, G{};
	cin >> B >> K >> G;
	int ans = (B - 2) / (K / G) + 1;
	cout << ans << "\n";
	return 0;
}
