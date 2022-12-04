#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{}, ans{};
		cin >> N;
		unordered_map<int, int> A;
		while (N--) {
			int M{}, x{}, t{};
			cin >> M;
			while (--M) {
				cin >> x;
				auto it = A.find(x);
				if (it != A.end()) {
					t = max(t, it->second);
				}
			}
			cin >> x;
			A[x] = t + 1;
			ans = max(ans, t + 1);
		}
		cout << tc << " " << ans << "\n";
	}
	return 0;
}
