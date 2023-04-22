#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int D[61][61][61];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(3);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B{1, 3, 9};
	memset(D, -1, sizeof D);
	queue<iii> q;
	D[A[0]][A[1]][A[2]] = 0;
	q.push({A[0], A[1], A[2]});
	while (q.size()) {
		auto [x, y, z] = q.front(); q.pop();
		sort(B.begin(), B.end());
		do {
			int nx = max(x - B[0], 0);
			int ny = max(y - B[1], 0);
			int nz = max(z - B[2], 0);
			if (D[nx][ny][nz] == -1) {
				D[nx][ny][nz] = D[x][y][z] + 1;
				q.push({nx, ny, nz});
			}
		} while (next_permutation(B.begin(), B.end()));
	}
	cout << D[0][0][0] << "\n";
	return 0;
}
