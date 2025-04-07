#include <bits/stdc++.h>

using namespace std;

vector<int> D(200001, -1);
vector<int> A(200001);
queue<int> q;

void solve(int x, int p) {
	if (x < 0 || x >= D.size()) {
		return;
	}
	if (D[x] == -1) {
		D[x] = D[p] + 1;
		A[x] = A[p];
		q.push(x);
	} else if (D[x] == D[p] + 1) {
		A[x] += A[p];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	D[N] = 0;
	A[N] = 1;
	q.push(N);
	while (q.size()) {
		int x = q.front(); q.pop();
		solve(x - 1, x);
		solve(x + 1, x);
		solve(2 * x, x);
	}
	cout << D[K] << "\n" << A[K] << "\n";
	return 0;
}
