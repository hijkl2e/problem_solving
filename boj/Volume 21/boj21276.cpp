#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<vector<int>> G(N);
	int M{};
	cin >> M;
	while (M--) {
		string s, t;
		cin >> s >> t;
		int u = lower_bound(A.begin(), A.end(), s) - A.begin();
		int v = lower_bound(A.begin(), A.end(), t) - A.begin();
		G[v].push_back(u);
	}
	vector<int> ind(N);
	for (int u = 0; u < N; ++u) {
		for (int v : G[u]) {
			++ind[v];
		}
	}
	vector<int> D(N);
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			D[v] = max(D[v], D[u] + 1);
			if (--ind[v] == 0) {
				q.push(v);
			}
		}
	}
	vector<int> B;
	for (int i = 0; i < N; ++i) {
		if (D[i] == 0) {
			B.push_back(i);
		}
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << A[B[i]] << (i == B.size() - 1 ? "\n" : " ");
	}
	for (int u = 0; u < N; ++u) {
		B.clear();
		for (int v : G[u]) {
			if (D[v] == D[u] + 1) {
				B.push_back(v);
			}
		}
		sort(B.begin(), B.end());
		cout << A[u] << " " << B.size();
		for (int v : B) {
			cout << " " << A[v];
		}
		cout << "\n";
	}
	return 0;
}
