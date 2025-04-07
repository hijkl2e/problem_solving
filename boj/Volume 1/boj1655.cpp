#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	while (N--) {
		int x{};
		cin >> x;
		if (pq1.size() == pq2.size()) {
			pq1.push(x);
		} else {
			pq2.push(x);
		}
		if (pq1.size() && pq2.size() && pq1.top() > pq2.top()) {
			int x = pq1.top(); pq1.pop();
			int y = pq2.top(); pq2.pop();
			pq1.push(y);
			pq2.push(x);
		}
		cout << pq1.top() << "\n";
	}
	return 0;
}
