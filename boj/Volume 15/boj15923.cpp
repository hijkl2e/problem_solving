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
	int ans{};
	for (int i = 0; i < N; ++i) {
		int j = (i + 1) % N;
		ans += abs(x[i] - x[j]) + abs(y[i] - y[j]);
	}
	cout << ans << "\n";
	return 0;
}
