#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans = N < K * (K + 1) / 2 ? -1 : (K - ((N - K * (K + 1) / 2) % K == 0));
	cout << ans << "\n";
	return 0;
}
