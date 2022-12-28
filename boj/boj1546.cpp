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
	int maxv = *max_element(A.begin(), A.end());
	double ans = accumulate(A.begin(), A.end(), 0) * 100.0 / maxv / N;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
