#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		cout << (N * (N + 1) * (2 * N + 1) / 6) << "\n";
	}
	return 0;
}
