#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M;
vector<vector<int>> A;

vector<vector<int>> solve(int Xd, int Yd) {
	vector<vector<int>> D(N, vector<int>(M, -1));
	priority_queue<iii> pq;
	pq.push({D[Xd][Yd] = N * M, Xd, Yd});
	while (pq.size()) {
		auto [d, x, y] = pq.top(); pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && D[nx][ny] == -1) {
				int nd = A[nx][ny] < 0 ? d : min(d, A[nx][ny]);
				pq.push({D[nx][ny] = nd, nx, ny});
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Xd{}, Yd{};
	cin >> N >> M >> Xd >> Yd;
	--Xd, --Yd;
	int K{};
	cin >> K;
	A.assign(N, vector<int>(M, -1));
	while (K--) {
		int x{}, y{};
		cin >> x >> y;
		A[x - 1][y - 1] = -2;
	}
	int T{};
	cin >> T;
	while (T--) {
		int x{}, y{}, z{};
		cin >> x >> y >> z;
		A[x - 1][y - 1] = z;
	}
	vector<vector<int>> D = solve(Xd, Yd);
	vector<int> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == -2) {
				B.push_back(D[i][j]);
			}
		}
	}
	sort(B.begin(), B.end());
	int ans{};
	for (int x : B) {
		if (ans + 1 < x) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
