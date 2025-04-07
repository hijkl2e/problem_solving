#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{};
	double S{};
	while (cin >> R >> S) {
		double V = sqrt((R * (S + .16)) / .067);
		int ans = lround(V);
		cout << ans << "\n";
	}
	return 0;
}
