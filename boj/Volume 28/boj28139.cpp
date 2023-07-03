#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> x(N);
	vector<int> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	double ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			ans += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}
	ans *= 2.0 / N;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
