#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{};
		cin >> N;
		cout << "Case #" << tc << ": ";
		if (N > 25) {
			cout << "Round " << (N > 4500 ? 1 : N > 1000 ? 2 : 3) << "\n";
		} else {
			cout << "World Finals\n";
		}
	}
	return 0;
}
