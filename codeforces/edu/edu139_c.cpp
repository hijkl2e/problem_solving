#include <bits/stdc++.h>

using namespace std;

const int dx[3]{-1, 1, 0};
const int dy[3]{0, 0, 1};

int M;
vector<string> A(2);

bool solve(int x) {
	if (A[x][0] == 'W') {
		return false;
	}
	vector<deque<bool>> vst(2, deque<bool>(M));
	int y{};
	vst[x][y] = true;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < 3; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 2 && 0 <= ny && ny < M && A[nx][ny] == 'B' && !vst[nx][ny]) {
				vst[nx][ny] = true;
				x = nx;
				y = ny;
				flag = true;
				break;
			}
		}
	}
	return y == M - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		cin >> M;
		cin.ignore();
		for (int i = 0; i < 2; ++i) {
			getline(cin, A[i]);
		}
		cout << ((solve(0) || solve(1)) ? "YES" : "NO") << "\n";
	}
	return 0;
}
