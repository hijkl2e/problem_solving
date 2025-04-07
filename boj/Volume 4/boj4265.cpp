#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
string S;
int cntr;
deque<bool> A(5);

void dfs(int x) {
	if (islower(S[x])) {
		return;
	}
	G[x].push_back(++cntr);
	dfs(cntr);
	if (S[x] == 'N') {
		return;
	}
	G[x].push_back(++cntr);
	dfs(cntr);
}

bool solve(int x) {
	char c = S[x];
	if (islower(c)) {
		return A[c - 'p'];
	} else if (c == 'N') {
		return !solve(G[x][0]);
	}
	bool res1 = solve(G[x][0]);
	bool res2 = solve(G[x][1]);
	if (c == 'K') {
		return res1 && res2;
	} else if (c == 'A') {
		return res1 || res2;
	} else if (c == 'C') {
		return !res1 || res2;
	} else {
		return res1 == res2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (getline(cin, S), S != "0") {
		G.assign(S.size(), vector<int>());
		cntr = 0;
		dfs(0);
		bool yes = true;
		for (int i = 0; i < 32; ++i) {
			for (int j = 0; j < 5; ++j) {
				A[j] = (i >> j) & 1;
			}
			yes &= solve(0);
		}
		cout << (yes ? "tautology" : "not") << "\n";
	}
	return 0;
}
