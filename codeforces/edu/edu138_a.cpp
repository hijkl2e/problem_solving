#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			int x{}, y{};
			cin >> x >> y;
		}
		cout << (N > M ? "YES" : "NO") << "\n";
	}
	return 0;
}
