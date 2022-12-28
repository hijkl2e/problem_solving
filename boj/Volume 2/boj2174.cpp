#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> d2i{
		{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}
	};
	int A{}, B{}, N{}, M{};
	cin >> A >> B >> N >> M;
	vector<ii> C(N + 1);
	vector<int> D(N + 1);
	for (int i = 1; i <= N; ++i) {
		char d{};
		cin >> C[i].first >> C[i].second >> d;
		D[i] = d2i[d];
	}
	string ans;
	while (M--) {
		int a{}, b{};
		char c{};
		cin >> a >> c >> b;
		if (ans.size()) {
			continue;
		}
		if (c == 'L') {
			D[a] = (D[a] + 3 * b) % 4;
			continue;
		} else if (c == 'R') {
			D[a] = (D[a] + b) % 4;
			continue;
		}
		while (b--) {
			auto &[x, y] = C[a];
			int nx = x + dx[D[a]];
			int ny = y + dy[D[a]];
			if (nx == 0 || nx == A + 1 || ny == 0 || ny == B + 1) {
				ans = "Robot " + to_string(a) + " crashes into the wall";
				break;
			}
			auto it = find(C.begin(), C.end(), make_pair(nx, ny));
			if (it == C.end()) {
				x = nx;
				y = ny;
			} else {
				ans = "Robot " + to_string(a) + " crashes into robot ";
				ans += to_string(it - C.begin());
				break;
			}
		}
	}
	if (ans.empty()) {
		ans = "OK";
	}
	cout << ans << "\n";
	return 0;
}
