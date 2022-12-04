#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(43201);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int d{}, t{};
		cin >> d >> t;
		++A[t - 2 * d];
		++A[t - d];
		++A[t];
	}
	int maxv = *max_element(A.begin(), A.end());
	int ans = (maxv + 1) / 2;
	cout << ans << "\n";
	return 0;
}
