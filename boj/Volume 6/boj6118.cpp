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
		G[v].push_back(u);
	}
	vector<int> D(N + 1, -1);
	queue<int> q;
	D[1] = 0;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	int ans_x = max_element(D.begin(), D.end()) - D.begin();
	int ans_y = D[ans_x];
	int ans_z = count(D.begin(), D.end(), ans_y);
	cout << ans_x << " " << ans_y << " " << ans_z << "\n";
	return 0;
}
