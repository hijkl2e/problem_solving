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
		cout << (N < 12 || M < 4 ? -1 : (11 * M + 4)) << "\n";
	}
	return 0;
}
