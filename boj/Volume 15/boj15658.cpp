#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N, maxv, minv;
vector<int> A, B(4);

void solve(int now, int step) {
	if (step == N) {
		maxv = max(maxv, now);
		minv = min(minv, now);
		return;
	}
	int x = A[step];
	for (int i = 0; i < 4; ++i) {
		if (B[i] == 0) {
			continue;
		}
		int y = i == 0 ? (now + x) : i == 1 ? (now - x) : i == 2 ? (now * x) : (now / x);
		--B[i];
		solve(y, step + 1);
		++B[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> B[i];
	}
	maxv = -INF;
	minv = INF;
	solve(A[0], 1);
	cout << maxv << "\n" << minv << "\n";
	return 0;
}
