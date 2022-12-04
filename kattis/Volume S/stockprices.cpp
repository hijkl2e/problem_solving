#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

void print(int x, char c) {
	if (x) {
		cout << x;
	} else {
		cout << "-";
	}
	cout << c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, sp{};
		cin >> N;
		priority_queue<ii, vector<ii>, greater<ii>> pq1;
		priority_queue<ii> pq2;
		while (N--) {
			string type, s;
			int x{}, y{};
			cin >> type >> x >> s >> s >> y;
			if (type == "buy") {
				pq2.push({y, x});
			} else {
				pq1.push({y, x});
			}
			while (pq1.size() && pq2.size()) {
				auto [y1, x1] = pq1.top();
				auto [y2, x2] = pq2.top();
				if (y1 > y2) {
					break;
				}
				pq1.pop(); pq2.pop();
				sp = y1;
				x = min(x1, x2);
				if (x1 - x) {
					pq1.push({y1, x1 - x});
				}
				if (x2 - x) {
					pq2.push({y2, x2 - x});
				}
			}
			print(pq1.size() ? pq1.top().first : 0, ' ');
			print(pq2.size() ? pq2.top().first : 0, ' ');
			print(sp, '\n');
		}
	}
	return 0;
}
