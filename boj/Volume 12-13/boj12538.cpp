#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int S{};
		cin >> S;
		vector<int> B, R;
		while (S--) {
			int x{};
			char c{};
			cin >> x >> c;
			if (c == 'B') {
				B.push_back(x);
			} else {
				R.push_back(x);
			}
		}
		sort(B.begin(), B.end());
		sort(R.begin(), R.end());
		int ans{};
		for (int i = min(B.size(), R.size()); i > 0; --i) {
			ans += B[B.size() - i] + R[R.size() - i] - 2;
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
