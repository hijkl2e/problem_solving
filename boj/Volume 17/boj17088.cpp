#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int solve(vector<int> &A, int a, int b) {
	int ret{};
	for (int i = 0; i < A.size(); ++i) {
		int x = abs(a + i * b - A[i]);
		if (x > 1) {
			return INF;
		}
		ret += x;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N < 3) {
		cout << "0\n";
		return 0;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = INF;
	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			ans = min(ans, solve(A, A[0] + i, (A[1] + j) - (A[0] + i)));
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
