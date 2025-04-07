#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		vector<vector<int>> G(N);
		vector<int> ind(N);
		for (int i = 0; i < N; ++i) {
			string s;
			getline(cin, s);
			for (int j = 0; j < N; ++j) {
				if (s[j] == '1') {
					G[i].push_back(j);
					++ind[j];
				}
			}
		}
		queue<int> q;
		for (int i = 0; i < N; ++i) {
			if (ind[i] == 0) {
				q.push(i);
			}
		}
		vector<set<int>> A(N);
		for (int i = 0; i < N; ++i) {
			int u = q.front(); q.pop();
			A[u].insert(i + 1);
			for (int v : G[u]) {
				for (int x : A[u]) {
					A[v].insert(x);
				}
				if (--ind[v] == 0) {
					q.push(v);
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			cout << A[i].size();
			for (int x : A[i]) {
				cout << " " << x;
			}
			cout << "\n";
		}
	}
	return 0;
}
