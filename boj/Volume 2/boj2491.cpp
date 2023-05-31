#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
	int ret{}, cnt = 1;
	for (int i = 1; i < A.size(); ++i) {
		if (A[i - 1] > A[i]) {
			ret = max(ret, cnt);
			cnt = 1;
		} else {
			++cnt;
		}
	}
	ret = max(ret, cnt);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = solve(A);
	reverse(A.begin(), A.end());
	ans = max(ans, solve(A));
	cout << ans << "\n";
	return 0;
}
