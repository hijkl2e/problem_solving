#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll sum{};
	double ans{};
	for (int i = 0; i < N; ++i) {
		sum += A[i];
		ans = max(ans, sum * 1.0 / (i + 1));
	}
	sum = 0;
	for (int i = N - 1; i >= 0; --i) {
		sum += A[i];
		ans = max(ans, sum * 1.0 / (N - i));
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
