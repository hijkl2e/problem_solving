#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	for (int i = 0; i < N; ++i) {
		B[i] -= A[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		while (B[i]) {
			int minv = abs(B[i]);
			int j = i + 1;
			for (; j < N; ++j) {
				if (B[j] == 0 || ((B[i] > 0) ^ (B[j] > 0))) {
					break;
				}
				minv = min(minv, abs(B[j]));
			}
			ans += minv;
			if (B[i] > 0) {
				minv *= -1;
			}
			for (int k = i; k < j; ++k) {
				B[k] += minv;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
