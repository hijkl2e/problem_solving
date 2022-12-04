#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans{};
	while (M--) {
		int x{};
		cin >> x;
		if (N >= x) {
			N -= x;
		} else {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
