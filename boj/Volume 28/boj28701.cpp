#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N * (N + 1) / 2;
	cout << ans << "\n";
	ans *= ans;
	cout << ans << "\n";
	cout << ans << "\n";
	return 0;
}
