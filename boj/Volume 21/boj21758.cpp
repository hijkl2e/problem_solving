#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	int ans = sum - A[0] - A[N - 1] + *max_element(A.begin() + 1, A.end() - 1);
	for (int k = 0; k < 2; ++k) {
		vector<int> B(A.begin(), A.end());
		partial_sum(A.begin(), A.end(), B.begin());
		for (int i = 1; i < N - 1; ++i) {
			ans = max(ans, 2 * sum - A[0] - A[i] - B[i]);
		}
		reverse(A.begin(), A.end());
	}
	cout << ans << "\n";
	return 0;
}
