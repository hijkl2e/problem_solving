#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int f{}, s{}, g{}, u{}, d{};
	cin >> f >> s >> g >> u >> d;
	vector<int> D(f + 1, -1);
	queue<int> q;
	D[s] = 0;
	q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		if (x + u <= f && D[x + u] == -1) {
			D[x + u] = D[x] + 1;
			q.push(x + u);
		}
		if (x - d > 0 && D[x - d] == -1) {
			D[x - d] = D[x] + 1;
			q.push(x - d);
		}
	}
	if (D[g] == -1) {
		cout << "use the stairs\n";
	} else {
		cout << D[g] << "\n";
	}
	return 0;
}
