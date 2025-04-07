#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> x(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	for (int a = 0; a < 10001; ++a) {
		if (N > 2 && (x[2] - x[1] - a * a * (x[1] - x[0])) % 10001) {
			continue;
		}
		for (int b = 0; b < 10001; ++b) {
			bool yes = true;
			for (int i = 0; i < N - 1; ++i) {
				if ((a * a * x[i] + a * b + b - x[i + 1]) % 10001) {
					yes = false;
					break;
				}
			}
			if (yes) {
				for (int i = 0; i < N; ++i) {
					cout << (a * x[i] + b) % 10001 << "\n";
				}
				return 0;
			}
		}
	}
	return 0;
}
