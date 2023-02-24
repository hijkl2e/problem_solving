#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;

void solve(int x) {
	if (B.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << B[i] << (i == M - 1 ? "\n" : " ");
		}
		return;
	}
	for (int i = x; i < N; ++i) {
		B.push_back(A[i]);
		solve(i + 1);
		B.pop_back();
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
	solve(0);
	return 0;
}
