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
	int ans{}, p{};
	for (int i = 1; i < N; ++i) {
		if (A[p] < A[i]) {
			ans = max(ans, i - p - 1);
			p = i;
		}
	}
	ans = max(ans, N - p - 1);
	cout << ans << "\n";
	return 0;
}
