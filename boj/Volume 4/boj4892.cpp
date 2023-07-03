#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		int x = (3 * N + 1) / 2 * 3 / 9;
		cout << tc << ". " << (N % 2 ? "odd" : "even") << " " << x << "\n";
	}
	return 0;
}
