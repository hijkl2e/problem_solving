#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{}, M{};
	cin >> N >> T >> M;
	queue<ii> L, R;
	for (int i = 0; i < M; ++i) {
		int x{};
		string s;
		cin >> x >> s;
		if (s == "left") {
			L.push({x, i});
		} else {
			R.push({x, i});
		}
	}
	int now{};
	bool left = true;
	vector<int> ans(M);
	while (L.size() || R.size()) {
		auto &q = left ? L : R;
		auto &opq = left ? R : L;
		int cnt{};
		while (q.size() && q.front().first <= now && cnt++ < N) {
			ans[q.front().second] = now + T;
			q.pop();
		}
		if (cnt || (opq.size() && opq.front().first <= now)) {
			left ^= true;
			now += T;
		} else {
			now = L.size() ? L.front().first : INF;
			now = min(now, R.size() ? R.front().first : INF);
		}
	}
	for (int i = 0; i < M; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
