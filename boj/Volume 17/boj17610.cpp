#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
deque<bool> B;

void solve(int n, int x) {
	if (n == N) {
		if (0 <= x && x < B.size()) {
			B[x] = true;
		}
		return;
	}
	solve(n + 1, x + A[n]);
	solve(n + 1, x - A[n]);
	solve(n + 1, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	B.resize(sum + 1);
	solve(0, 0);
	int ans = sum - accumulate(B.begin() + 1, B.end(), 0);
	cout << ans << "\n";
	return 0;
}
