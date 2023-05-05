#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(10001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

bool solve(int x, int y) {
	int cnt{};
	for (int i = 0; i < 4; ++i) {
		if (x % 10 != y % 10) {
			++cnt;
		}
		x /= 10, y /= 10;
	}
	return cnt == 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p = sieve();
	vector<int> P;
	for (int i = 1000; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	vector<vector<int>> G(10001);
	for (int i = 0; i < P.size(); ++i) {
		for (int j = i + 1; j < P.size(); ++j) {
			if (solve(P[i], P[j])) {
				G[P[i]].push_back(P[j]);
				G[P[j]].push_back(P[i]);
			}
		}
	}
	int T{};
	cin >> T;
	vector<int> D(10001);
	queue<int> q;
	while (T--) {
		int s{}, g{};
		cin >> s >> g;
		fill(D.begin(), D.end(), -1);
		D[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int y : G[x]) {
				if (D[y] == -1) {
					D[y] = D[x] + 1;
					q.push(y);
				}
			}
		}
		if (D[g] == -1) {
			cout << "Impossible\n";
		} else {
			cout << D[g] << "\n";
		}
	}
	return 0;
}
