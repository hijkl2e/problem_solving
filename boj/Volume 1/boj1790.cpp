#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A;
	for (int i = 1, j = 9;; ++i, j *= 10) {
		if (N <= j) {
			A.push_back(i * N);
			break;
		}
		A.push_back(i * j);
		N -= j;
	}
	if (accumulate(A.begin(), A.end(), 0) < K) {
		cout << "-1\n";
		return 0;
	}
	int ans{};
	for (int i = 0, j = 1; i < A.size(); ++i, j *= 10) {
		if (K <= A[i]) {
			string s = to_string(j + (K - 1) / (i + 1));
			ans = s[(K - 1) % (i + 1)] - '0';
			break;
		}
		K -= A[i];
	}
	cout << ans << "\n";
	return 0;
}
