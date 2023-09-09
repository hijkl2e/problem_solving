#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	int N = accumulate(A.begin(), A.end(), 0);
	int K{};
	cin >> K;
	double ans{};
	for (int i = 0; i < M; ++i) {
		if (A[i] < K) {
			continue;
		}
		double x = 1;
		for (int j = 0; j < K; ++j) {
			x *= A[i] - j;
		}
		ans += x;
	}
	for (int i = 0; i < K; ++i) {
		ans /= N - i;
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
