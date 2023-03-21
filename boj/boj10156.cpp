#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{}, M{};
	cin >> K >> N >> M;
	int ans = max(K * N - M, 0);
	cout << ans << "\n";
	return 0;
}
