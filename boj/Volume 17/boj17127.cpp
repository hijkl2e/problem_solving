#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	B[0] = 1;
	for (int i = 1; i <= N; ++i) {
		B[i] = A[i] * B[i - 1];
	}
	int ans{};
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				ans = max(ans, B[i] + B[j] / B[i] + B[k] / B[j] + B[N] / B[k]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
