#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		vector<vector<iii>> G(101);
		map<string, int> c2i;
		int M{};
		cin >> M;
		while (M--) {
			string s1, s2;
			int t1{}, t2{};
			cin >> s1 >> s2 >> t1 >> t2;
			t1 = (t1 + 6) % 24;
			t2 = (t1 + t2) % 24;
			if (t1 < t2 && t2 <= 12) {
				int u = c2i.insert({s1, c2i.size()}).first->second;
				int v = c2i.insert({s2, c2i.size()}).first->second;
				G[u].push_back({v, t1, t2});
			}
		}
		string s1, s2;
		cin >> s1 >> s2;
		int s = c2i.insert({s1, c2i.size()}).first->second;
		int t = c2i.insert({s2, c2i.size()}).first->second;
		vector<int> D(101, INF);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({D[s] = 0, s});
		while (pq.size()) {
			auto [d, u] = pq.top(); pq.pop();
			if (D[u] < d) {
				continue;
			}
			for (auto &[v, t1, t2] : G[u]) {
				int nd = D[u] / 24 * 24 + (D[u] % 24 > t1 ? 24 : 0) + t2;
				if (D[v] > nd) {
					pq.push({D[v] = nd, v});
				}
			}
		}
		cout << "Test Case " << tc << ".\n";
		if (D[t] == INF) {
			cout << "There is no route Vladimir can take.\n";
		} else {
			cout << "Vladimir needs " << D[t] / 24 << " litre(s) of blood.\n";
		}
	}
	return 0;
}
