#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	queue<ii> q;
	for (int i = 0; i < M; ++i) {
		if (A[0][i] == '0') {
			A[0][i] = '2';
			q.push({0, i});
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == '0') {
				A[nx][ny] = '2';
				q.push({nx, ny});
			}
		}
	}
	cout << (find(A[N - 1].begin(), A[N - 1].end(), '2') != A[N - 1].end() ? "YES" : "NO") << "\n";
	return 0;
}
