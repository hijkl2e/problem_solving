#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int solve(int x) {
	for (int i = 10000; i > 0; i /= 10) {
		if (x % (10 * i) / i) {
			x -= i;
			break;
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{}, G{};
	cin >> N >> T >> G;
	vector<int> D(100000, INF);
	queue<int> q;
	D[N] = 0;
	q.push(N);
	while (q.size()) {
		int x = q.front(); q.pop();
		if (x + 1 < D.size() && D[x + 1] == INF) {
			D[x + 1] = D[x] + 1;
			q.push(x + 1);
		}
		if (2 * x < D.size()) {
			int y = solve(2 * x);
			if (D[y] == INF) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	if (D[G] > T) {
		cout << "ANG\n";
	} else {
		cout << D[G] << "\n";
	}
	return 0;
}
