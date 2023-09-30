#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	K += 60;
	int ans = 1500 * min(N, K) + 3000 * max(N - K, 0);
	cout << ans << "\n";
	return 0;
}
