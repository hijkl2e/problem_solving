#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const double PI = acos(-1);

int square(int x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<double> mag{
		1 / PI, 1 / PI / PI, 1 / PI / PI / PI,
		-1 / PI / PI / PI, -1 / PI / PI, -1 / PI
	};
	vector<char> pc{
		'0', 'O', 'o', '.', 'x', 'X'
	};
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	cin.ignore();
	vector<string> grid(N, string(M, '%'));
	vector<ii> A, B;
	while (Q--) {
		int x{}, y{};
		char c{};
		cin >> y >> x >> c;
		--x, --y;
		if (c == '+') {
			A.push_back({x, y});
		} else {
			B.push_back({x, y});
		}
		grid[x][y] = c;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (grid[i][j] == '+' || grid[i][j] == '-') {
				continue;
			}
			double val{};
			for (auto &p : A) {
				val += 1.0 / sqrt(square(p.first - i) + square(p.second - j));
			}
			for (auto &p : B) {
				val -= 1.0 / sqrt(square(p.first - i) + square(p.second - j));
			}
			for (int k = 0; k < 6; ++k) {
				if (val > mag[k]) {
					grid[i][j] = pc[k];
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << grid[i] << "\n";
	}
	return 0;
}
