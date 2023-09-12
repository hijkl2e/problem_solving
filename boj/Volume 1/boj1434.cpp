#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans{};
	while (N--) {
		int x{};
		cin >> x;
		ans += x;
	}
	while (M--) {
		int x{};
		cin >> x;
		ans -= x;
	}
	cout << ans << "\n";
	return 0;
}
