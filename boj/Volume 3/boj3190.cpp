#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N + 1, vector<int>(N + 1));
	while (K--) {
		int x{}, y{};
		cin >> x >> y;
		A[x][y] = 2;
	}
	int L{};
	cin >> L;
	vector<int> B(10101);
	while (L--) {
		int x{};
		char c{};
		cin >> x >> c;
		B[x] = c == 'D' ? 1 : 3;
	}
	int x{}, y{}, d{};
	x = y = 1;
	deque<ii> C{{x, y}};
	A[x][y] = 1;
	int t{};
	while (true) {
		++t;
		x += dx[d];
		y += dy[d];
		if (x == 0 || x == N + 1 || y == 0 || y == N + 1 || A[x][y] == 1) {
			break;
		}
		C.push_front({x, y});
		if (A[x][y] == 0) {
			auto &[r, c] = C.back();
			A[r][c] = 0;
			C.pop_back();
		}
		A[x][y] = 1;
		d = (d + B[t]) % 4;
	}
	cout << t << "\n";
	return 0;
}
