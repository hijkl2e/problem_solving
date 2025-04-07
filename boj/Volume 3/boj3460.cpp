#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		while (N) {
			int x = N & -N;
			N -= x;
			cout << __builtin_ctz(x) << (N ? " " : "\n");
		}
	}
	return 0;
}
