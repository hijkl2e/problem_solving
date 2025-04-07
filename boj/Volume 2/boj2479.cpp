#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		string S;
		getline(cin, S);
		for (int j = 0; j < K; ++j) {
			A[i] = 2 * A[i] + S[j] - '0';
		}
	}
	vector<vector<int>> G(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (__builtin_popcount(A[i] ^ A[j]) == 1) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	int s{}, t{};
	cin >> s >> t;
	vector<int> D(N + 1, -1);
	vector<int> par(N + 1, -1);
	queue<int> q;
	D[t] = 0;
	q.push(t);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				par[y] = x;
				q.push(y);
			}
		}
	}
	if (D[s] == -1) {
		cout << "-1\n";
		return 0;
	}
	while (s != t) {
		cout << s << " ";
		s = par[s];
	}
	cout << t << "\n";
	return 0;
}
