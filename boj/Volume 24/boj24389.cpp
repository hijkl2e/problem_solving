#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = __builtin_popcount(N ^ (~N + 1));
	cout << ans << "\n";
	return 0;
}
