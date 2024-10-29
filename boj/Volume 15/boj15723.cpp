#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> D(26, vector<int>(26, INF));
	for (int i = 0; i < 26; ++i) {
		D[i][i] = 0;
	}
	while (N--) {
		char a{}, b{};
		string is;
		cin >> a >> is >> b;
		D[a - 'a'][b - 'a'] = 1;
	}
	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int M{};
	cin >> M;
	while (M--) {
		char a{}, b{};
		string is;
		cin >> a >> is >> b;
		cout << (D[a - 'a'][b - 'a'] < INF ? "T" : "F") << "\n";
	}
	return 0;
}
