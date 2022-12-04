#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, N{};
	cin >> R >> N;
	deque<bool> chk(R + 1);
	while (N--) {
		int x{};
		cin >> x;
		chk[x] = true;
	}
	int ans{};
	for (int i = 1; i <= R; ++i) {
		if (!chk[i]) {
			ans = i;
			break;
		}
	}
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "too late\n";
	}
	return 0;
}
