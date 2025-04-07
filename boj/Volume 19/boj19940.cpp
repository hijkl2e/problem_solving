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
		int a = (N + 24) / 60;
		N %= 60;
		int b = N < 36 ? (N + 4) / 10 : 0;
		int c = N > 35 ? (64 - N) / 10 : 0;
		int x = N / 10, y = N % 10;
		int d = y < 5 ? y : y == 5 && x < 4 ? 5 : 0;
		int e = y > 5 ? 10 - y : y == 5 && x > 3 ? 5 : 0;
		cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
	}
	return 0;
}
