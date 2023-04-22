#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	int minv = INF, mini{};
	for (int i = 0; i < N; ++i) {
		int maxv{};
		for (int j = 0; j < N; ++j) {
			maxv = max(maxv, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
		if (minv > maxv) {
			minv = maxv;
			mini = i;
		}
	}
	cout << x[mini] << " " << y[mini] << "\n";
	return 0;
}
