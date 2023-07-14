#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i <= N - 2; ++i) {
		ans += i * (N - i - 2);
	}
	ans = ans * N / 4;
	cout << ans << "\n";
	return 0;
}
