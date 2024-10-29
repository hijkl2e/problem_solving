#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> x(M);
	vector<int> y(M);
	for (int i = 0; i < M; ++i) {
		cin >> x[i] >> y[i];
	}
	int a{}, b{};
	a = b = N;
	for (int i = 0; i < M; ++i) {
		if (x[i] >= a || y[i] >= b) {
			continue;
		} else if ((a - x[i]) * b <= (b - y[i]) * a) {
			a = x[i];
		} else {
			b = y[i];
		}
	}
	int ans = a * b;
	cout << ans << "\n";
	return 0;
}
