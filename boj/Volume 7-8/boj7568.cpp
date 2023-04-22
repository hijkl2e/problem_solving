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
	for (int i = 0; i < N; ++i) {
		int cnt = 1;
		for (int j = 0; j < N; ++j) {
			if (x[i] < x[j] && y[i] < y[j]) {
				++cnt;
			}
		}
		cout << cnt << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
