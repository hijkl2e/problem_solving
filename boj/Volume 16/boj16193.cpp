#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans{};
	if (N % 2) {
		ans = max(2 * (accumulate(A.begin() + N / 2 + 1, A.end(), 0LL)
					- accumulate(A.begin(), A.begin() + N / 2 - 1, 0LL)) - A[N / 2] - A[N / 2 - 1],
					2 * (accumulate(A.begin() + N / 2 + 2, A.end(), 0LL)
					- accumulate(A.begin(), A.begin() + N / 2, 0LL)) + A[N / 2] + A[N / 2 + 1]);
	} else {
		ans = 2 * (accumulate(A.begin() + N / 2 + 1, A.end(), 0LL)
				- accumulate(A.begin(), A.begin() + N / 2 - 1, 0LL)) + A[N / 2] - A[N / 2 - 1];
	}
	cout << ans << "\n";
	return 0;
}
