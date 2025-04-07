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
	sort(A.begin(), A.end());
	double ans = max(accumulate(A.begin(), A.end(), 0LL), N * (N > 1 ? A[N - 2] : 0LL)) * 1.0 / N;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
