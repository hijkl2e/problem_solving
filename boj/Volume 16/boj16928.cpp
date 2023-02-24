#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(101);
	for (int i = 1; i < 101; ++i) {
		A[i] = i;
	}
	int N{}, M{};
	cin >> N >> M;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = y;
	}
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		A[u] = v;
	}
	vector<int> D(101, -1);
	queue<int> q;
	D[1] = 0;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = 1; i < 7 && x + i < 101; ++i) {
			int y = A[x + i];
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	cout << D[100] << "\n";
	return 0;
}
