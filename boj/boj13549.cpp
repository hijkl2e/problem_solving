#include <bits/stdc++.h>

using namespace std;

vector<int> D(200001, -1);
deque<int> dq;

void solve(int x, int p) {
	if (x < 0 || x >= D.size() || D[x] != -1) {
		return;
	}
	if (x == 2 * p) {
		D[x] = D[p];
		dq.push_front(x);
	} else {
		D[x] = D[p] + 1;
		dq.push_back(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	D[N] = 0;
	dq.push_back(N);
	while (dq.size()) {
		int x = dq.front(); dq.pop_front();
		solve(x - 1, x);
		solve(x + 1, x);
		solve(2 * x, x);
	}
	cout << D[K] << "\n";
	return 0;
}
