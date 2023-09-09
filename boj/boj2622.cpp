#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans += max((N - i) / 2 - max(i, N / 2 - i + 1) + 1, 0);
	}
	cout << ans << "\n";
	return 0;
}
