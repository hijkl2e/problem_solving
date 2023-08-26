#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[7]{-1, -1, -1, 0, 1, 1, 0};
const int dy[7]{-1, 0, 1, 1, 1, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int gx{}, gy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'F') {
				gx = i, gy = j;
			}
		}
	}
	int ans{};
	queue<ii> q;
	q.push({gx, gy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 7; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == '.') {
				A[nx][ny] = '#';
				q.push({nx, ny});
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
