#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	int sum{}, minv = 1e9;
	for (int i = M; i <= N; ++i) {
		bool yes = i > 1;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				yes = false;
				break;
			}
		}
		if (yes) {
			sum += i;
			minv = min(minv, i);
		}
	}
	if (sum) {
		cout << sum << "\n" << minv << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
