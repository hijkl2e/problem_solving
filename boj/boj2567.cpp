#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<deque<bool>> A(101, deque<bool>(101));
	int N{};
	cin >> N;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				A[x + i][y + j] = true;
			}
		}
	}
	int ans{};
	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j < 101; ++j) {
			if (A[i][j] ^ A[i - 1][j]) {
				++ans;
			}
			if (A[i][j] ^ A[i][j - 1]) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
