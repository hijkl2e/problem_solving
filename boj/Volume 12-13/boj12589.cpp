#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{}, K{};
		cin >> N >> K;
		cout << "Case #" << tc << ": ";
		cout << ((K + 1) % (1 << N) == 0 ? "ON" : "OFF") << "\n";
	}
	return 0;
}
