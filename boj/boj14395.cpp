#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s{}, t{};
	cin >> s >> t;
	if (s == t) {
		cout << "0\n";
		return 0;
	}
	map<int, int> D, par;
	queue<int> q;
	D[t] = 1;
	q.push(t);
	while (q.size()) {
		int x = q.front(); q.pop();
		int y = sqrt(x);
		if (y * y == x && (D[y] == 0 || D[y] == D[x] + 1)) {
			D[y] = D[x] + 1;
			par[y] = max(par[y], 2);
			q.push(y);
		}
		y = x / 2;
		if (2 * y == x && (D[y] == 0 || D[y] == D[x] + 1)) {
			D[y] = D[x] + 1;
			par[y] = max(par[y], 1);
			q.push(y);
		}
		if (x == 1 && (D[s] == 0 || D[s] == D[x] + 1)) {
			D[s] = D[x] + 1;
			par[s] = max(par[s], 0);
			q.push(s);
		}
	}
	auto it = D.find(s);
	if (it == D.end()) {
		cout << "-1\n";
		return 0;
	}
	string ans;
	while (s != t) {
		int p = par[s];
		ans += p == 2 ? "*" : p == 1 ? "+" : "/";
		s = p == 2 ? s * s : p == 1 ? 2 * s : 1;
	}
	cout << ans << "\n";
	return 0;
}
