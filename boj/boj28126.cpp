#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int R{}, U{}, X{};
	for (char c : S) {
		if (c == 'R') {
			++R;
		} else if (c == 'U') {
			++U;
		} else {
			++X;
		}
	}
	int K{};
	cin >> K;
	int ans{};
	while (K--) {
		int x{}, y{};
		cin >> x >> y;
		--x, --y;
		int minv = min({x, y, X});
		x -= minv, y -= minv;
		if (x <= R && y <= U) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
