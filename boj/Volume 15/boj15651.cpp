#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;

void solve() {
	if (A.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << A[i] << (i == M - 1 ? "\n" : " ");
		}
		return;
	}
	for (int i = 1; i <= N; ++i) {
		A.push_back(i);
		solve();
		A.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	solve();
	return 0;
}
