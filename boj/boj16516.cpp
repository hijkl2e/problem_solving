#include <bits/stdc++.h>

using namespace std;

using dd = pair<double, double>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<dd> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	double ans{};
	for (int i = 0; i < N - 1; ++i) {
		ans = max(ans, abs(A[i + 1].second - A[i].second) * 1.0 / (A[i + 1].first - A[i].first));
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
