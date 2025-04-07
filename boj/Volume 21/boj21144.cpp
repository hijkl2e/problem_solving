#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N;
	for (int i = 1; i < N; ++i) {
		int x{};
		char c{};
		cin >> c;
		x = c - '0';
		if (i >= 10) {
			cin >> c;
			x = 10 * x + c - '0';
		}
		if (x != i) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
