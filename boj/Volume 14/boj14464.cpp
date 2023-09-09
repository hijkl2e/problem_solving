#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{};
	cin >> C >> N;
	vector<iii> A;
	while (C--) {
		int t{};
		cin >> t;
		A.push_back({t, 1, -1});
	}
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		A.push_back({a, 0, b});
	}
	sort(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans{};
	for (auto &[a, b, c] : A) {
		if (b) {
			while (pq.size() && pq.top() < a) {
				pq.pop();
			}
			if (pq.size()) {
				pq.pop();
				++ans;
			}
		} else {
			pq.push(c);
		}
	}
	cout << ans << "\n";
	return 0;
}
