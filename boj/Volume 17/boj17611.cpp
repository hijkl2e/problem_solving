#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> x(N + 1);
	vector<int> y(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
		x[i] += 500000;
		y[i] += 500000;
	}
	x[N] = x[0];
	y[N] = y[0];
	vector<int> A(1000001);
	vector<int> B(1000001);
	for (int i = 0; i < N; ++i) {
		if (x[i] == x[i + 1]) {
			++A[min(y[i], y[i + 1])];
			--A[max(y[i], y[i + 1])];
		} else {
			++B[min(x[i], x[i + 1])];
			--B[max(x[i], x[i + 1])];
		}
	}
	partial_sum(A.begin(), A.end(), A.begin());
	partial_sum(B.begin(), B.end(), B.begin());
	int ans = *max_element(A.begin(), A.end());
	ans = max(ans, *max_element(B.begin(), B.end()));
	cout << ans << "\n";
	return 0;
}
