#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	int ans = -1;
	while (N--) {
		int s{}, t{};
		cin >> s >> t;
		if (s + t <= X) {
			ans = max(ans, s);
		}
	}
	cout << ans << "\n";
	return 0;
}
