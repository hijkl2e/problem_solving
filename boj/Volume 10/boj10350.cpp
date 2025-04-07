#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		A[N + i] = A[i];
	}
	int sum = accumulate(A.begin(), A.begin() + N, 0);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		int x{};
		for (int j = 0; j < N; ++j) {
			x += A[i + j];
			if (x < 0) {
				ans += (abs(x) - 1) / sum + 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
