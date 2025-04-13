#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> X(N);
	vector<int> Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				int area = X[j] * Y[i] - X[i] * Y[j];
				area += X[k] * Y[j] - X[j] * Y[k];
				area += X[i] * Y[k] - X[k] * Y[i];
				ans = max(ans, area);
			}
		}
	}
	cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << "\n";
	return 0;
}
