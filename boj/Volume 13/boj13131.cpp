#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 2 * N * ((N + 1) * (N + 14) + 5);
	cout << ans << "\n";
	return 0;
}
