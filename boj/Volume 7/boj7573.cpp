#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{}, M{};
	cin >> N >> L >> M;
	vector<int> x(M);
	vector<int> y(M);
	for (int i = 0; i < M; ++i) {
		cin >> x[i] >> y[i];
	}
	int ans{};
	for (int w = 1; 2 * (w + 1) <= L; ++w) {
		int h = L / 2 - w;
		for (int i = 0; i < M; ++i) {
			vector<int> A;
			for (int j = 0; j < M; ++j) {
				if (x[i] <= x[j] && x[j] <= x[i] + w) {
					A.push_back(y[j]);
				}
			}
			sort(A.begin(), A.end());
			for (int j = 0, k = 1; j < A.size(); ++j) {
				while (k < A.size() && A[k] <= A[j] + h) {
					++k;
				}
				ans = max(ans, k - j);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
