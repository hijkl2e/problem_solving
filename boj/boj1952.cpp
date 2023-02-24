#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans = 2 * min(N, M) - (N > M ? 1 : 2);
	cout << ans << "\n";
	return 0;
}
