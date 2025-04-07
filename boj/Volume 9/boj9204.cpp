#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int d1(int x, int y) {
	return x + y - 2;
}

int d2(int x, int y) {
	return x - y + 7;
}

string c2s(int x, int y) {
	ostringstream oss;
	char c = x + 'A';
	oss << c << " " << y + 1;
	return oss.str();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		char c{};
		int x1{}, y1{}, x2{}, y2{};
		cin >> c >> y1;
		x1 = c - 'A';
		--y1;
		cin >> c >> y2;
		x2 = c - 'A';
		--y2;
		if ((x1 + y1 + x2 + y2) % 2) {
			cout << "Impossible\n";
			continue;
		}
		vector<ii> rec;
		rec.push_back({x1, y1});
		if (x1 != x2 || y1 != y2) {
			if (d1(x1, y1) != d1(x2, y2) && d2(x1, y1) != d2(x2, y2)) {
				for (int i = 0; i < 8 && rec.size() == 1; ++i) {
					for (int j = 0; j < 8; ++j) {
						if ((d1(x1, y1) == d1(i, j) || d2(x1, y1) == d2(i, j))
								&& (d1(i, j) == d1(x2, y2) || d2(i, j) == d2(x2, y2))) {
							rec.push_back({i, j});
							break;
						}
					}
				}
			}
			rec.push_back({x2, y2});
		}
		cout << rec.size() - 1;
		for (auto &p : rec) {
			cout << " " << c2s(p.first, p.second);
		}
		cout << "\n";
	}
	return 0;
}
