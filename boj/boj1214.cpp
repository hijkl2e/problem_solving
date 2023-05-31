#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int D{}, P{}, Q{};
	cin >> D >> P >> Q;
	if (P > Q) {
		swap(P, Q);
	}
	int ans = 2e9;
	for (int i = min((D - 1) / Q + 1, P - 1); i >= 0; --i) {
		int x = D - i * Q;
		ans = min(ans, i * Q + (x > 0 ? ((x - 1) / P + 1) * P : 0));
	}
	cout << ans << "\n";
	return 0;
}
