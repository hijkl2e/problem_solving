#include <bits/stdc++.h>

using namespace std;

vector<int> A;

int dfs(int x) {
	if (A[x] != -1) {
		return A[x];
	}
	A[x] = 0;
	int y = x, z{};
	while (y) {
		int r = y % 10;
		z += r * r;
		y /= 10;
	}
	return A[x] = dfs(z);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(max(N + 1, 1000), -1);
	A[1] = 1;
	deque<bool> P(N + 1, true);
	P[0] = P[1] = false;
	for (int i = 2; i <= N; ++i) {
		if (P[i]) {
			for (int j = 2 * i; j <= N; j += i) {
				P[j] = false;
			}
		}
	}
	for (int i = 2; i <= N; ++i) {
		if (P[i] && dfs(i)) {
			cout << i << "\n";
		}
	}
	return 0;
}
