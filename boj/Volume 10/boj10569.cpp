#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int V{}, E{};
		cin >> V >> E;
		int ans = E - V + 2;
		cout << ans << "\n";
	}
	return 0;
}
