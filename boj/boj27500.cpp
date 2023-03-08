#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int hp[2], d[4], P[321];
int dp[321][301][301];

int dmg(int s, int e) {
	int ret{};
	for (int i = s; i < e; ++i) {
		ret += P[i] == 2 ? d[2] : P[i] == 3 ? d[3] : 0;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 2; ++i) {
		cin >> hp[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> d[i];
	}
	int M{};
	cin >> M;
	while (M--) {
		int t{};
		string cmd;
		cin >> t >> cmd;
		if (cmd == "attack") {
			P[t + 4] = 2;
			continue;
		}
		for (int i = 0; i < 9; ++i) {
			P[t + i] = 1;
		}
		P[t + 9] = 3;
	}
	memset(dp, -1, sizeof dp);
	dp[0][hp[0]][hp[1]] = 0;
	for (int i = 0; i < 301; ++i) {
		for (int j = 1; j <= hp[0]; ++j) {
			for (int k = 1; k <= hp[1]; ++k) {
				if (dp[i][j][k] == -1) {
					continue;
				}
				dp[i + 1][max(j - dmg(i, i + 1), 0)][k] = 0;
				dp[i + 5][max(j - dmg(i, i + 5), 0)][max(k - (P[i + 4] == 1 ? 0 : d[0]), 0)] = 1;
				dp[i + 15][max(j - dmg(i + 14, i + 15), 0)][max(k - (P[i + 14] == 1 ? 0 : d[1]), 0)] = 2;
			}
		}
	}
	int x = -1, y = -1, z{};
	for (int i = 1; i < 302; ++i) {
		for (int j = hp[0]; j > 0; --j) {
			if (dp[i][j][0] != -1) {
				x = i, y = j;
				i = 301;
				break;
			}
		}
	}
	if (x == -1) {
		cout << "NO\n";
		return 0;
	}
	vector<ii> A;
	while (x) {
		if (dp[x][y][z] == 1) {
			x -= 5;
			y += dmg(x, x + 5);
			z += P[x + 4] == 1 ? 0 : d[0];
			A.push_back({x, 1});
		} else if (dp[x][y][z] == 2) {
			x -= 15;
			y += dmg(x + 14, x + 15);
			z += P[x + 14] == 1 ? 0 : d[1];
			A.push_back({x, 2});
		} else {
			--x;
			y += dmg(x, x + 1);
		}
		while (dp[x][y][z] == -1) {
			--z;
		}
	}
	reverse(A.begin(), A.end());
	cout << "YES\n";
	for (auto &p : A) {
		cout << p.first << " " << (p.second == 1 ? "attack" : "counter strike") << "\n";
	}
	return 0;
}
