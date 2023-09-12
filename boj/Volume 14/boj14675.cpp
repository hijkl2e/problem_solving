#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		++A[u], ++A[v];
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int t{}, k{};
		cin >> t >> k;
		cout << (t == 2 || A[k] > 1 ? "yes" : "no") << "\n";
	}
	return 0;
}
