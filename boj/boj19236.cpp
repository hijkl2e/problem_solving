#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8]{0, -1, -1, -1, 0, 1, 1, 1};

ii find(vector<vector<ii>> &A, int x) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (A[i][j].first == x) {
				return {i, j};
			}
		}
	}
	return {-1, -1};
}

int solve(vector<vector<ii>> A) {
	for (int i = 1; i < 17; ++i) {
		auto [x, y] = find(A, i);
		if (x == -1) {
			continue;
		}
		int &d = A[x][y].second;
		for (int j = 0; j < 8; ++j) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && A[nx][ny].first) {
				swap(A[x][y], A[nx][ny]);
				break;
			}
			d = (d + 1) % 8;
		}
	}
	auto [x, y] = find(A, 0);
	int d = A[x][y].second;
	int nx = x + dx[d];
	int ny = y + dy[d];
	int ret{};
	while (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
		if (A[nx][ny].first == -1) {
			nx += dx[d];
			ny += dy[d];
			continue;
		}
		int p = A[nx][ny].first;
		A[nx][ny].first = 0;
		A[x][y].first = -1;
		ret = max(ret, p + solve(A));
		A[x][y].first = 0;
		A[nx][ny].first = p;
		nx += dx[d];
		ny += dy[d];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ii>> A(4, vector<ii>(4));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> A[i][j].first >> A[i][j].second;
			--A[i][j].second;
		}
	}
	int ans = A[0][0].first;
	A[0][0].first = 0;
	ans += solve(A);
	cout << ans << "\n";
	return 0;
}
