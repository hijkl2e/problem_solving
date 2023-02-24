#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;

void solve(int x) {
	if (A.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << A[i] << (i == M - 1 ? "\n" : " ");
		}
		return;
	}
	for (int i = x; i <= N; ++i) {
		A.push_back(i);
		solve(i + 1);
		A.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	solve(1);
	return 0;
}
