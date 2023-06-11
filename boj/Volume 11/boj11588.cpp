#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(M);
	for (auto &[u, v] : A) {
		cin >> u >> v;
		--u, --v;
	}
	int ans{};
	for (int i = 0; i < (1 << N); ++i) {
		bool yes = true;
		for (auto &[u, v] : A) {
			if ((i >> u) & (i >> v) & 1) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
