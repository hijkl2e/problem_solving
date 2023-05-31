#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	vector<string> A(2);
	for (int i = 0; i < 2; ++i) {
		getline(cin, A[i]);
		A[i] += "1";
	}
	vector<vector<int>> D(2, vector<int>(N + 1, -1));
	queue<ii> q;
	D[0][0] = 0;
	q.push({0, 0});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		if (y < N && A[x][y + 1] == '1' && D[x][y + 1] == -1) {
			D[x][y + 1] = D[x][y] + 1;
			q.push({x, y + 1});
		}
		if (y && A[x][y - 1] == '1' && D[x][y - 1] == -1 && D[x][y] < y - 1) {
			D[x][y - 1] = D[x][y] + 1;
			q.push({x, y - 1});
		}
		int nx = x ^ 1;
		int ny = min(y + K, N);
		if (A[nx][ny] == '1' && D[nx][ny] == -1) {
			D[nx][ny] = D[x][y] + 1;
			q.push({nx, ny});
		}
	}
	cout << (D[0][N] != -1 || D[1][N] != -1) << "\n";
	return 0;
}
