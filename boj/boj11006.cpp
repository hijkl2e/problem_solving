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
		int x = 2 * M - N, y = N - M;
		cout << x << " " << y << "\n";
	}
	return 0;
}
