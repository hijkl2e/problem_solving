#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int min = 1e9 + 7;
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (min > x) {
			min = x;
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}
