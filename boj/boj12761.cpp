#include <bits/stdc++.h>

using namespace std;

vector<int> D;
queue<int> q;

void solve(int x, int p) {
	if (0 <= x && x < D.size() && D[x] == -1) {
		D[x] = D[p] + 1;
		q.push(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, N{}, M{};
	cin >> A >> B >> N >> M;
	D.assign(100001, -1);
	D[N] = 0;
	q.push(N);
	while (q.size()) {
		int x = q.front(); q.pop();
		solve(x + 1, x); solve(x - 1, x);
		solve(x + A, x); solve(x - A, x);
		solve(x + B, x); solve(x - B, x);
		solve(x * A, x); solve(x * B, x);
	}
	cout << D[M] << "\n";
	return 0;
}
