#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int w{}, h{};
		cin >> w >> h;
		if (w == 136) {
			ans += 1000;
		} else if (w == 142) {
			ans += 5000;
		} else if (w == 148) {
			ans += 10000;
		} else {
			ans += 50000;
		}
	}
	cout << ans << "\n";
	return 0;
}
