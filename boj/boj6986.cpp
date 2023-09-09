#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		double x{};
		cin >> x;
		A[i] = 10 * x + EPS;
	}
	sort(A.begin(), A.end());
	double ans_x = accumulate(A.begin() + K, A.end() - K, 0) / 10.0 / (N - 2 * K) + EPS;
	fill(A.begin(), A.begin() + K, A[K]);
	fill(A.end() - K, A.end(), A[N - K - 1]);
	double ans_y = accumulate(A.begin(), A.end(), 0) / 10.0 / N + EPS;
	cout << fixed << setprecision(2);
	cout << ans_x << "\n";
	cout << ans_y << "\n";
	return 0;
}
