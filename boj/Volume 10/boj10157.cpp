#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, R{}, K{};
	cin >> C >> R >> K;
	if (C * R < K) {
		cout << "0\n";
		return 0;
	}
	int x = 1, y{}, d{}, z = R;
	while (K--) {
		x += dx[d];
		y += dy[d];
		if (--z == 0) {
			d = (d + 1) % 4;
			z = d % 2 ? --C : --R;
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
