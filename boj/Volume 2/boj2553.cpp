#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x = 1, t{};
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j % 2 == 0) {
			j /= 2;
			++t;
		}
		while (j % 5 == 0) {
			j /= 5;
			--t;
		}
		x = j * x % 10;
	}
	while (t--) {
		x = 2 * x % 10;
	}
	cout << x << "\n";
	return 0;
}
