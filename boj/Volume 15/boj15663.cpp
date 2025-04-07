#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;
deque<bool> C;

void solve() {
	if (B.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << B[i] << (i == M - 1 ? "\n" : " ");
		}
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (C[i]) {
			continue;
		}
		B.push_back(A[i]);
		C[i] = true;
		solve();
		B.pop_back();
		C[i] = false;
		while (i + 1 < N && A[i] == A[i + 1]) {
			++i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	C.resize(N + 1);
	solve();
	return 0;
}
