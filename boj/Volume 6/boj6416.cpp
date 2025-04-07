#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int tc = 1;; ++tc) {
		vector<vector<int>> G(14);
		vector<vector<int>> H(14);
		int u{}, v{}, cnt{};
		while (cin >> u >> v, u > 0) {
			G[u].push_back(v);
			H[v].push_back(u);
			++cnt;
		}
		if (u == -1) {
			break;
		}
		cout << "Case " << tc << " is ";
		if (cnt == 0) {
			cout << "a tree.\n";
			continue;
		}
		bool yes = true;
		for (int i = 1; i < 14; ++i) {
			if (H[i].size() > 1) {
				yes = false;
				break;
			} else if (G[i].size() || H[i].size()) {
				--cnt;
			}
		}
		yes &= cnt == -1;
		cout << (yes ? "" : "not ") << "a tree.\n";
	}
	return 0;
}
