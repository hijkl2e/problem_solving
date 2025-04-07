#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M;
bool C[501][501][4];
vector<string> A;

int dfs(int x, int y, int d) {
	if (!(0 <= x && x < N && 0 <= y && y < M && A[x][y] != 'C')) {
		return 0;
	}
	if (C[x][y][d]) {
		return INF;
	}
	C[x][y][d] = true;
	if (A[x][y] == '\\') {
		d ^= 3;
	} else if (A[x][y] == '/') {
		d ^= 1;
	}
	return dfs(x + dx[d], y + dy[d], d) + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sx{}, sy{};
	cin >> sx >> sy;
	--sx, --sy;
	vector<int> B(4);
	for (int i = 0; i < 4; ++i) {
		memset(C, 0, sizeof(C));
		B[i] = dfs(sx, sy, i);
	}
	int maxi = max_element(B.begin(), B.end()) - B.begin();
	cout << "URDL"[maxi] << "\n";
	if (B[maxi] >= INF) {
		cout << "Voyager\n";
	} else {
		cout << B[maxi] << "\n";
	}
	return 0;
}
