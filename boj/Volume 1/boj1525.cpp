#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int A[3][3];
int D[362880];

void load(int id) {
	static vector<int> B(9);
	for (int i = 8; i >= 0; --i) {
		B[i] = id % (9 - i);
		id /= (9 - i);
	}
	static vector<int> C;
	C.resize(9);
	for (int i = 0; i < 9; ++i) {
		C[i] = i;
	}
	for (int i = 0; i < 9; ++i) {
		auto it = C.begin() + B[i];
		A[*it / 3][*it % 3] = i;
		C.erase(it);
	}
}

int save() {
	static vector<int> B(9);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			B[A[i][j]] = 3 * i + j;
		}
	}
	static vector<int> C;
	C.resize(9);
	for (int i = 0; i < 9; ++i) {
		C[i] = i;
	}
	int ret{};
	for (int i = 0; i < 9; ++i) {
		auto it = find(C.begin(), C.end(), B[i]);
		ret = (9 - i) * ret + it - C.begin();
		C.erase(it);
	}
	return ret;
}

void bfs(int s) {
	queue<int> q;
	D[s] = 0;
	q.push(s);
	while (q.size()) {
		int z = q.front(); q.pop();
		load(z);
		int x{}, y{};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (A[i][j] == 8) {
					x = i, y = j;
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				swap(A[x][y], A[nx][ny]);
				int nz = save();
				if (D[nz] == -1) {
					D[nz] = D[z] + 1;
					q.push(nz);
				}
				swap(A[x][y], A[nx][ny]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
			A[i][j] = (A[i][j] + 8) % 9;
		}
	}
	memset(D, -1, sizeof D);
	bfs(save());
	cout << D[0] << "\n";
	return 0;
}
