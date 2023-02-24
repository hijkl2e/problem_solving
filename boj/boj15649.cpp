#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;
deque<bool> B;

void solve() {
	if (A.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << A[i] << (i == M - 1 ? "\n" : " ");
		}
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (B[i]) {
			continue;
		}
		A.push_back(i);
		B[i] = true;
		solve();
		A.pop_back();
		B[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	B.resize(N + 1);
	solve();
	return 0;
}
