#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	--K;
	int ans = M;
	while (K) {
		K = (K - 1) / 2;
		++ans;
	}
	ans = min<int>(ans, __builtin_ctz(N));
	cout << ans << "\n";
	return 0;
}
