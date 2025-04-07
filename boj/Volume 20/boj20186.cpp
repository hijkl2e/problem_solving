#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.rbegin(), A.rend());
	int ans = accumulate(A.begin(), A.begin() + K, 0) - K * (K - 1) / 2;
	cout << ans << "\n";
	return 0;
}
