#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8]{1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(5);
	for (int i = 0; i < 5; ++i) {
		getline(cin, A[i]);
	}
	int cnt{};
	bool yes = true;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] == '.') {
				continue;
			}
			for (int k = 0; k < 8; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] == 'k') {
					yes = false;
					break;
				}
			}
			++cnt;
		}
	}
	yes &= cnt == 9;
	cout << (yes ? "valid" : "invalid") << "\n";
	return 0;
}
