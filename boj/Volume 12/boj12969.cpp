#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

int A[31][31][31][451];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	memset(A, -1, sizeof A);
	queue<rec> q;
	q.push({0, 0, 0, 0});
	int x{}, y{};
	x = y = -1;
	while (q.size()) {
		auto [a, b, c, d] = q.front(); q.pop();
		if (a == N) {
			if (d == K) {
				x = b, y = c;
				break;
			}
			continue;
		}
		if (A[a + 1][b + 1][c][d] == -1) {
			A[a + 1][b + 1][c][d] = 0;
			q.push({a + 1, b + 1, c, d});
		}
		if (A[a + 1][b][c + 1][d + b] == -1) {
			A[a + 1][b][c + 1][d + b] = 1;
			q.push({a + 1, b, c + 1, d + b});
		}
		if (A[a + 1][b][c][d + b + c] == -1) {
			A[a + 1][b][c][d + b + c] = 2;
			q.push({a + 1, b, c, d + b + c});
		}
	}
	if (x == -1) {
		cout << "-1\n";
		return 0;
	}
	string ans;
	while (N) {
		if (A[N][x][y][K] == 0) {
			ans += "A";
			--x;
		} else if (A[N][x][y][K] == 1) {
			ans += "B";
			--y, K -= x;
		} else {
			ans += "C";
			K -= x + y;
		}
		--N;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
