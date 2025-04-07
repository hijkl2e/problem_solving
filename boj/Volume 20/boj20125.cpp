#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<string> A;

int solve(int x, int y, int d) {
	int ret{};
	while (0 <= x && x < N && 0 <= y && y < N && A[x][y] == '*') {
		++ret;
		x += dx[d];
		y += dy[d];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int hx{}, hy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == '*') {
				hx = i + 1, hy = j;
				i = N;
				break;
			}
		}
	}
	vector<int> B(5);
	B[0] = solve(hx, hy - 1, 3);
	B[1] = solve(hx, hy + 1, 2);
	B[2] = solve(hx + 1, hy, 0);
	B[3] = solve(hx + B[2] + 1, hy - 1, 0);
	B[4] = solve(hx + B[2] + 1, hy + 1, 0);
	cout << hx + 1 << " " << hy + 1 << "\n";
	for (int i = 0; i < 5; ++i) {
		cout << B[i] << (i == 4 ? "\n" : " ");
	}
	return 0;
}
