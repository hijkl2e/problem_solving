#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N) {
		if (N == 1) {
			cout << "1\n";
			continue;
		}
		int ans{}, x{};
		ans = x = 1;
		while (x) {
			x = (10 * x + 1) % N;
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
