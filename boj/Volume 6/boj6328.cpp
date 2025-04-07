#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	for (int tc = 1; cin >> N >> M, N; ++tc) {
		cin.ignore();
		vector<vector<string>> A(N);
		for (int i = 0; i < N; ++i) {
			string S;
			getline(cin, S);
			S = S.substr(0, S.find(':'));
			int s{};
			while (s < S.size()) {
				int e = S.find(".,", s);
				if (e == -1) {
					e = S.size() - 1;
				}
				A[i].push_back(S.substr(s, e - s + 1));
				s = e + 3;
			}
		}
		vector<string> B(M);
		for (int i = 0; i < M; ++i) {
			getline(cin, B[i]);
		}
		map<string, int> n2i{{"Erdos, P.", 0}};
		for (int i = 0; i < N; ++i) {
			for (auto &s : A[i]) {
				n2i.insert({s, n2i.size()});
			}
		}
		for (int i = 0; i < M; ++i) {
			n2i.insert({B[i], n2i.size()});
		}
		vector<vector<int>> G(n2i.size());
		for (auto &v : A) {
			for (int j = 0; j < v.size(); ++j) {
				for (int k = j + 1; k < v.size(); ++k) {
					int a = n2i[v[j]];
					int b = n2i[v[k]];
					G[a].push_back(b);
					G[b].push_back(a);
				}
			}
		}
		vector<int> D(G.size(), -1);
		queue<int> q;
		D[0] = 0;
		q.push(0);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int y : G[x]) {
				if (D[y] == -1) {
					D[y] = D[x] + 1;
					q.push(y);
				}
			}
		}
		if (tc > 1) {
			cout << "\n";
		}
		cout << "Database #" << tc << "\n";
		for (int i = 0; i < M; ++i) {
			int d = D[n2i[B[i]]];
			cout << B[i] << ": " << (d == -1 ? "infinity" : to_string(d)) << "\n";
		}
	}
	return 0;
}
