#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		vector<string> A(N + 2);
		A[0] = A[N + 1] = string(M + 2, '.');
		for (int i = 1; i <= N; ++i) {
			getline(cin, A[i]);
			A[i] = "." + A[i] + ".";
		}
		deque<bool> B(26);
		string s;
		getline(cin, s);
		if (s != "0") {
			for (char c : s) {
				B[c - 'a'] = true;
			}
		}
		vector<deque<bool>> vst(N + 2, deque<bool>(M + 2));
		vector<queue<ii>> q(27);
		vst[0][0] = true;
		q[26].push({0, 0});
		int ans{};
		while (q[26].size()) {
			auto [x, y] = q[26].front(); q[26].pop();
			if (A[x][y] == '$') {
				++ans;
			} else if (islower(A[x][y]) && !B[A[x][y] - 'a']) {
				int z = A[x][y] - 'a';
				B[z] = true;
				while (q[z].size()) {
					q[26].push(q[z].front());
					q[z].pop();
				}
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N + 2 && 0 <= ny && ny < M + 2 && A[nx][ny] != '*' && !vst[nx][ny]) {
					vst[nx][ny] = true;
					int z = A[nx][ny] - 'A';
					q[isupper(A[nx][ny]) && !B[z] ? z : 26].push({nx, ny});
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
