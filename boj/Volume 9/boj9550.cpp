#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		int ans{};
		while (N--) {
			int x{};
			cin >> x;
			ans += x / K;
		}
		cout << ans << "\n";
	}
	return 0;
}
