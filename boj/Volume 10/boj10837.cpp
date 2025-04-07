#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, C{};
	cin >> K >> C;
	while (C--) {
		int M{}, N{};
		cin >> M >> N;
		int ans = M >= N ? (M - N < K - M + 3) : (N - M < K - N + 2);
		cout << ans << "\n";
	}
	return 0;
}
