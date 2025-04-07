#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{2, -2, 0, 0};
const int dy[4]{0, 0, 2, -2};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(K);
	for (auto &[x, y] : A) {
		cin >> x >> y;
	}
	set<ii> S;
	for (auto &[x, y] : A) {
		for (int j = 0; j < 4; ++j) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
				S.insert({nx, ny});
			}
		}
	}
	for (auto &p : A) {
		S.erase(p);
	}
	cout << S.size() << "\n";
	return 0;
}
