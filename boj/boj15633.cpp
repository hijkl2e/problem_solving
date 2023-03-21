#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		if (N % i == 0) {
			ans += i;
		}
	}
	ans = 5 * ans - 24;
	cout << ans << "\n";
	return 0;
}
