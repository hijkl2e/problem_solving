#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, T{}, D{};
	cin >> S >> T >> D;
	int ans = D / (2 * S) * T;
	cout << ans << "\n";
	return 0;
}
