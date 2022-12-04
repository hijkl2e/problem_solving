#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, vector<int>> c2v{
		{'A', {0}}, {'B', {5, 10}}, {'C', {6, 3, 9, 12}}, {'D', {15}}
	};
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> G(N + 2);
	G[0] = G[N + 1] = string(M + 2, 'A');
	for (int i = 1; i <= N; ++i) {
		getline(cin, G[i]);
		G[i] = "A" + G[i] + "A";
	}
	vector<vector<int>> A(N + 2, vector<int>(M + 2));
	bool yes = true;
	for (int i = 1; i <= N + 1; ++i) {
		for (int j = 1; j <= M + 1; ++j) {
			A[i][j] = -1;
			for (int k : c2v[G[i][j]]) {
				if (((A[i - 1][j] ^ (k >> 2)) & 1) || ((A[i][j - 1] ^ (k >> 2)) & 2)) {
					continue;
				}
				A[i][j] = k;
				break;
			}
			if (A[i][j] == -1) {
				yes = false;
			}
		}
	}
	cout << (yes ? "Possible" : "Impossible") << "\n";
	return 0;
}
