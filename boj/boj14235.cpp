#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	priority_queue<int> pq;
	while (N--) {
		int k{};
		cin >> k;
		if (k) {
			while (k--) {
				int x{};
				cin >> x;
				pq.push(x);
			}
		} else {
			if (pq.size()) {
				cout << pq.top() << "\n";
				pq.pop();
			} else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}
