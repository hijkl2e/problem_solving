#include <bits/stdc++.h>

using namespace std;

int dp[4][4][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	while (N--) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int x = s1 == "kor" ? 1 : (s1.size() - 1);
		int y = s2.size() - 3;
		int z = s3.size() - 2;
		++dp[x][y][z];
	}
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			for (int k = 1; k < 4; ++k) {
				for (int l = 0; l < 7; ++l) {
					dp[(l & 4) ? i : 0][(l & 2) ? j : 0][(l & 1) ? k : 0] += dp[i][j][k];
				}
			}
		}
	}
	while (M--) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int x = s1 == "kor" ? 1 : (s1.size() - 1);
		int y = max<int>(s2.size() - 3, 0);
		int z = max<int>(s3.size() - 2, 0);
		cout << dp[x][y][z] << "\n";
	}
	return 0;
}
