#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	int ans = min(M, K) + min(N - M, N - K);
	cout << ans << "\n";
	return 0;
}
