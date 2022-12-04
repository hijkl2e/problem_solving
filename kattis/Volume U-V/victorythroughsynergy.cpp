#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> G(10);
	int C{};
	cin >> C;
	while (C--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<string> N(10);
	vector<string> L(10);
	vector<string> T(10);
	for (int i = 0; i < 10; ++i) {
		string s;
		cin >> s >> N[i] >> L[i] >> T[i];
	}
	vector<vector<int>> A(10, vector<int>(10));
	for (int i = 0; i < 10; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			A[i][j] = A[j][i] = N[i] == N[j] ? T[i] == T[j] ? 3 : L[i] == L[j] ? 2 : 1
								: T[i] == T[j] ? 2 : L[i] == L[j] ? 1 : 0;
		}
	}
	vector<int> B(10);
	for (int i = 0; i < 10; ++i) {
		B[i] = i;
	}
	bool yes{};
	do {
		bool flag = true;
		for (int i = 0; i < 10; ++i) {
			int cnt{};
			for (int x : G[i]) {
				cnt += A[B[i]][B[x]];
			}
			if (cnt < G[i].size()) {
				flag = false;
				break;
			}
		}
		if (flag) {
			yes = true;
			break;
		}
	} while (next_permutation(B.begin(), B.end()));
	cout << (yes ? "yes" : "no") << "\n";
	return 0;
}
