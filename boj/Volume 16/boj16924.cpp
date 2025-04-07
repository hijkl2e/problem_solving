#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

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
	vector<deque<bool>> B(N);
	vector<iii> C;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '.') {
				continue;
			}
			int k{};
			bool flag = true;
			while (flag) {
				++k;
				for (int l = 0; l < 4; ++l) {
					int nx = i + k * dx[l];
					int ny = j + k * dy[l];
					if (nx == -1 || nx == N || ny == -1 || ny == M || A[nx][ny] == '.') {
						flag = false;
						break;
					}
				}
			}
			if (--k == 0) {
				continue;
			}
			C.push_back({i + 1, j + 1, k});
			for (; k >= 0; --k) {
				for (int l = 0; l < 4; ++l) {
					int nx = i + k * dx[l];
					int ny = j + k * dy[l];
					B[nx][ny] = true;
				}
			}
		}
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '*' && !B[i][j]) {
				yes = false;
			}
		}
	}
	if (yes) {
		cout << C.size() << "\n";
		for (auto &[a, b, c] : C) {
			cout << a << " " << b << " " << c << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
