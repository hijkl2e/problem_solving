#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
	int ret{}, prev{};
	for (int x : A) {
		if (x == prev) {
			prev = 0;
			continue;
		}
		ret = max(ret, min(prev, x));
		prev = max(prev, x);
	}
	ret = max(ret, prev);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int ans = max(solve(A), solve(B));
	cout << ans << "\n";
	return 0;
}
