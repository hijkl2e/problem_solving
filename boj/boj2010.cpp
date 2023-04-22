#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		ans += x;
	}
	ans -= N - 1;
	cout << ans << "\n";
	return 0;
}
