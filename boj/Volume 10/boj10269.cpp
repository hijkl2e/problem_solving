#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{};
	cin >> C >> N;
	int x{};
	bool yes = true;
	while (N--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		if (x < a) {
			yes = false;
			break;
		}
		x = x - a + b;
		if (x > C || (c && x < C)) {
			yes = false;
			break;
		}
	}
	yes &= !x;
	cout << (yes ? "possible" : "impossible") << "\n";
	return 0;
}
