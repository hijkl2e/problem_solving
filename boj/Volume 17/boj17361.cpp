#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

vector<int> solve(vector<int> &B, int p) {
	vector<int> A(B.begin(), B.end());
	++A[p];
	fill(A.begin() + p + 1, A.end(), 1);
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (y < p && A[y] < A[x] + 1) {
				return {-1};
			}
			A[y] = max(A[y], A[x] + 1);
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	if (count(ind.begin() + 1, ind.end(), 0) < N) {
		return {-1};
	}
	return A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> B[i];
	}
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	int lo = 0, hi = N + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		vector<int> A = solve(B, mid);
		if (A[0] == -1) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	if (lo) {
		vector<int> A = solve(B, lo);
		for (int i = 1; i <= N; ++i) {
			cout << A[i] << (i == N ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
