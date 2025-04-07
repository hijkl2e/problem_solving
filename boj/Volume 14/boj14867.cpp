#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

map<ii, int> D;
queue<ii> q;

void solve(int x, int y, int d) {
	if (D.insert({{x, y}, d}).second) {
		q.push({x, y});
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	D[{0, 0}] = 0;
	q.push({0, 0});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		int d = D[{x, y}];
		solve(a, y, d + 1);
		solve(x, b, d + 1);
		solve(0, y, d + 1);
		solve(x, 0, d + 1);
		int z = min(a - x, y);
		solve(x + z, y - z, d + 1);
		z = min(b - y, x);
		solve(x - z, y + z, d + 1);
	}
	auto it = D.find({c, d});
	cout << (it == D.end() ? -1 : it->second) << "\n";
	return 0;
}
