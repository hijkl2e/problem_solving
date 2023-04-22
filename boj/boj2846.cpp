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
	int ans{};
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && A[j - 1] < A[j]) {
			++j;
		}
		if (i < j - 1) {
			ans = max(ans, A[j - 1] - A[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}
