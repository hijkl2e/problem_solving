#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[i] = i;
	}
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		swap(A[u], A[v]);
	}
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
