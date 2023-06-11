#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> s2i{
		{'S', 0}, {'P', 1}, {'R', 2}
	};
	int R{};
	cin >> R;
	vector<int> A(R);
	for (int i = 0; i < R; ++i) {
		char c{};
		cin >> c;
		A[i] = s2i[c];
	}
	int N{};
	cin >> N;
	vector<vector<int>> B(R, vector<int>(3));
	while (N--) {
		for (int i = 0; i < R; ++i) {
			char c{};
			cin >> c;
			++B[i][s2i[c]];
		}
	}
	int ans{};
	for (int i = 0; i < R; ++i) {
		ans += 2 * B[i][(A[i] + 1) % 3] + B[i][A[i]];
	}
	cout << ans << "\n";
	ans = 0;
	for (int i = 0; i < R; ++i) {
		int maxv{};
		for (int j = 0; j < 3; ++j) {
			maxv = max(maxv, 2 * B[i][(j + 1) % 3] + B[i][j]);
		}
		ans += maxv;
	}
	cout << ans << "\n";
	return 0;
}
