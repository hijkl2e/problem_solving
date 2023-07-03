#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, m{}, M{}, T{}, R{};
	cin >> N >> m >> M >> T >> R;
	if (m + T > M) {
		cout << "-1\n";
		return 0;
	}
	int X = m, t{};
	while (N--) {
		while (X + T > M) {
			X = max(X - R, m);
			++t;
		}
		X += T;
		++t;
	}
	cout << t << "\n";
	return 0;
}
