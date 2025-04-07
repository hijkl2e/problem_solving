#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int B{};
		double P{};
		cin >> B >> P;
		cout << fixed << setprecision(10);
		for (int i = -1; i < 2; ++i) {
			cout << (B + i) / P * 60 << (i == 1 ? "\n" : " ");
		}
	}
	return 0;
}
