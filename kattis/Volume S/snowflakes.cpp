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
		unordered_map<int, int> A;
		int S{}, ans{};
		for (int i = 0; i < N; ++i) {
			int x{};
			cin >> x;
			auto it = A.find(x);
			if (it == A.end()) {
				A.insert({x, i});
			} else {
				if (S <= it->second) {
					S = it->second + 1;
				}
				it->second = i;
			}
			ans = max(ans, i - S + 1);
		}
		cout << ans << "\n";
	}
	return 0;
}
