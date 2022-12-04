#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{}, P{};
	cin >> N >> L >> P;
	vector<int> A(N);
	ii ans;
	while (P--) {
		int x{};
		cin >> x;
		int d{};
		if (x > N * L) {
			d = x - (N * L - L / 2);
		} else {
			d = (x + L / 2) % L;
			d = min(d, L - d);
		}
		ans.first = max(ans.first, d);
		ans.second = max(ans.second, ++A[min(x / L, N - 1)]);
	}
	cout << ans.first << "\n";
	cout << ans.second << "\n";
	return 0;
}
