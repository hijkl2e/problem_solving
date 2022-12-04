#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int L{}, M{};
		cin >> L >> M;
		L *= 100;
		queue<int> lq, rq;
		while (M--) {
			int x{};
			string s;
			cin >> x >> s;
			if (s == "left") {
				lq.push(x);
			} else {
				rq.push(x);
			}
		}
		int ans{};
		bool left = true;
		while (lq.size() || rq.size()) {
			auto &q = left ? lq : rq;
			int sum{};
			while (q.size() && sum + q.front() <= L) {
				sum += q.front();
				q.pop();
			}
			left ^= true;
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
