#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{}, x{};
	cin >> N >> M >> K;
	--M;
	int i = 2;
	for (; M >= i + 2; ++i) {
		x = (x + 2 * i + 4) % N;
		M -= i + 2;
	}
	int ans{};
	if (M < 2) {
		ans = (x + 2 * M + K) % N;
	} else {
		ans = (x + K * i + M + 2) % N;
	}
	cout << ans << "\n";
	return 0;
}
