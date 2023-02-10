#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	int maxr{}, maxc{};
	while (R--) {
		int x{};
		cin >> x;
		maxr = max(maxr, x);
	}
	while (C--) {
		int y{};
		cin >> y;
		maxc = max(maxc, y);
	}
	cout << (maxr == maxc ? "possible" : "impossible") << "\n";
	return 0;
}
