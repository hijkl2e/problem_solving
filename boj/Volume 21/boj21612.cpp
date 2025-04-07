#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 5 * N - 400;
	cout << ans << "\n";
	cout << (ans < 100 ? 1 : ans > 100 ? -1 : 0) << "\n";
	return 0;
}
