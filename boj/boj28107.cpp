#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<queue<int>> q(200001);
	for (int i = 1; i <= N; ++i) {
		int k{};
		cin >> k;
		while (k--) {
			int x{};
			cin >> x;
			q[x].push(i);
		}
	}
	vector<int> A(N + 1);
	while (M--) {
		int x{};
		cin >> x;
		if (q[x].size()) {
			++A[q[x].front()];
			q[x].pop();
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
