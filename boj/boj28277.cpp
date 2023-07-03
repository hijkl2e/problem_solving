#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<set<int>> S(N + 1);
	for (int i = 1; i <= N; ++i) {
		int n{};
		cin >> n;
		while (n--) {
			int x{};
			cin >> x;
			S[i].insert(x);
		}
	}
	while (Q--) {
		int q{}, a{}, b{};
		cin >> q >> a;
		if (q == 2) {
			cout << S[a].size() << "\n";
			continue;
		}
		cin >> b;
		if (S[a].size() < S[b].size()) {
			swap(S[a], S[b]);
		}
		auto it = S[a].begin();
		for (int x : S[b]) {
			it = S[a].insert(it, x);
		}
		S[b].clear();
	}
	return 0;
}
