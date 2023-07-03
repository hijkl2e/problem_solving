#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> n2t;
	while (N--) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 7; ++j) {
				string s;
				cin >> s;
				if (s == "-") {
					continue;
				}
				n2t[s] += i == 1 ? 6 : i == 3 ? 10 : 4;
			}
		}
	}
	int maxv = -INF, minv = INF;
	for (auto &p : n2t) {
		maxv = max(maxv, p.second);
		minv = min(minv, p.second);
	}
	bool yes = n2t.empty() || maxv - minv <= 12;
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
