#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ls = pair<ll, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	priority_queue<ls, vector<ls>, greater<ls>> pq;
	set<string> left;
	while (N--) {
		ll Q{}, T{}, S{};
		string M;
		cin >> Q >> T;
		if (Q == 1) {
			cin >> M >> S;
			pq.push({K * T - S, M});
		} else if (Q == 2) {
			while (pq.size() && left.count(pq.top().second)) {
				pq.pop();
			}
			if (pq.size()) {
				cout << pq.top().second << "\n";
				pq.pop();
			} else {
				cout << "doctor takes a break\n";
			}
		} else {
			cin >> M;
			left.insert(M);
		}
	}
	return 0;
}
