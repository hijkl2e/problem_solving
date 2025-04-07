#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> s2c;
	while (N--) {
		int h{}, m{};
		char c{};
		string s;
		cin >> h >> c >> m >> s;
		s2c[s] += h * 60 + m;
	}
	for (auto &[u, v] : s2c) {
		v = (v > 100 ? (v - 51) / 50 * 3 : 0) + 10;
	}
	vector<is> A;
	for (auto &p : s2c) {
		A.push_back({-p.second, p.first});
	}
	sort(A.begin(), A.end());
	for (auto &p : A) {
		cout << p.second << " " << -p.first << "\n";
	}
	return 0;
}
