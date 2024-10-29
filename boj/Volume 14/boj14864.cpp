#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<int> A(N + 1);
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[i] = G[i].size() + i - B[i];
		for (int x : G[i]) {
			++B[x];
		}
	}
	deque<bool> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		C[A[i]] = true;
	}
	if (count(C.begin(), C.end(), true) == N) {
		for (int i = 1; i <= N; ++i) {
			cout << A[i] << (i == N ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
