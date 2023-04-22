#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
	int ret{};
	for (int i = 1; i < A.size() - 1; ++i) {
		int x = A[i];
		A.erase(A.begin() + i);
		int res = solve(A);
		A.insert(A.begin() + i, x);
		ret = max(ret, res + A[i - 1] * A[i + 1]);
	}
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
	cout << solve(A) << "\n";
	return 0;
}
