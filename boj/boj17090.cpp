#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const string udlr = "UDLR";
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N + 2);
	A[0] = A[N + 1] = string(M + 2, '#');
	for (int i = 1; i <= N; ++i) {
		getline(cin, A[i]);
		A[i] = "#" + A[i] + "#";
	}
	vector<deque<bool>> B(N + 2, deque<bool>(M + 2));
	queue<ii> q;
	for (int i = 0; i < M + 2; ++i) {
		q.push({0, i});
		q.push({N + 1, i});
	}
	for (int i = 1; i <= N; ++i) {
		q.push({i, 0});
		q.push({i, M + 1});
	}
	int ans{};
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= N && 1 <= ny && ny <= M && A[nx][ny] == udlr[i] && !B[nx][ny]) {
				B[nx][ny] = true;
				q.push({nx, ny});
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
