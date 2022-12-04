#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[12]{0, 0, 2018, -2018, 1118, 1118, 1680, 1680, -1118, -1118, -1680, -1680};
const int dy[12]{2018, -2018, 0, 0, 1680, -1680, 1118, -1118, 1680, -1680, 1118, -1118};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	set<ii> S;
	int ans{};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		for (int i = 0; i < 12; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (S.count({nx, ny})) {
				++ans;
			}
		}
		S.insert({x, y});
	}
	cout << ans << "\n";
	return 0;
}
