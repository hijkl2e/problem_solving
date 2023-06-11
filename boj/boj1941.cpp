#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<string> A(5);
set<int> S;
int ans;

void solve(int n, int cnt, int vst) {
	if (cnt < n - 3 || !S.insert(vst).second) {
		return;
	}
	if (n == 7) {
		++ans;
		return;
	}
	for (int i = 0; i < 25; ++i) {
		if ((vst & (1 << i)) == 0) {
			continue;
		}
		int x = i / 5, y = i % 5;
		for (int j = 0; j < 4; ++j) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			int nz = 5 * nx + ny;
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && (vst & (1 << nz)) == 0) {
				solve(n + 1, cnt + (A[nx][ny] == 'S'), vst | (1 << nz));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 5; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			solve(1, A[i][j] == 'S', 1 << (5 * i + j));
		}
	}
	cout << ans << "\n";
	return 0;
}
