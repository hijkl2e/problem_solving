#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int i = 0; i < T; ++i) {
		if (i) {
			cout << "\n";
		}
		int N{}, M{};
		cin >> N >> M;
		while (M--) {
			cout << string(N, 'X') << "\n";
		}
	}
	return 0;
}
