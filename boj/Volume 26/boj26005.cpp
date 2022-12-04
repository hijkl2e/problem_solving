#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	if (N > 1) {
		ans = (N * N + 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}
