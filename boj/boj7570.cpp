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
	vector<int> B(N + 1);
	for (int i = 0; i < N; ++i) {
		B[A[i]] = i;
	}
	int ans{};
	for (int i = 1, j = 2; i <= N; i = j++) {
		while (j <= N && B[j - 1] < B[j]) {
			++j;
		}
		ans = max(ans, j - i);
	}
	ans = N - ans;
	cout << ans << "\n";
	return 0;
}
