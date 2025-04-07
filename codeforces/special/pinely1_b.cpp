#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		set<int> S;
		for (int i = 0; i < N; ++i) {
			int x{};
			cin >> x;
			S.insert(x);
		}
		int ans = (S.size() == 2) ? (N / 2 + 1) : N;
		cout << ans << "\n";
	}
	return 0;
}
