#include <bits/stdc++.h>

using namespace std;

int N, cnt;
vector<deque<bool>> G;
vector<int> ord, ans;

void solve(int step, int last) {
	if (step == N) {
		copy(ord.begin(), ord.end(), ans.begin());
		++cnt;
		return;
	}
	for (int i = N - 1; i >= 0; --i) {
		if (ord[i] == -1 && (last == -1 || G[last][i])) {
			ord[i] = step;
			solve(step + 1, i);
			ord[i] = -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		cin >> N;
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		map<string, int> c2i;
		for (int i = 0; i < N; ++i) {
			c2i[A[i]] = i;
		}
		G.assign(N, deque<bool>(N, true));
		int M{};
		cin >> M;
		while (M--) {
			string s1, s2;
			cin >> s1 >> s2;
			int u = c2i[s1];
			int v = c2i[s2];
			G[u][v] = G[v][u] = false;
		}
		ord.assign(N, -1);
		ans.resize(N);
		cnt = 0;
		solve(0, -1);
		cout << cnt << "\n";
		for (int i = 0; i < N; ++i) {
			int x = find(ans.begin(), ans.end(), i) - ans.begin();
			cout << A[x] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
