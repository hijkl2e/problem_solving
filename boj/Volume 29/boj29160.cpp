#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<priority_queue<int>> A(12);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		A[x].push(y);
	}
	while (K--) {
		for (int i = 1; i < 12; ++i) {
			if (A[i].empty()) {
				continue;
			}
			int x = A[i].top(); A[i].pop();
			A[i].push(max(x - 1, 0));
		}
	}
	int ans{};
	for (int i = 1; i < 12; ++i) {
		if (A[i].empty()) {
			continue;
		}
		ans += A[i].top();
	}
	cout << ans << "\n";
	return 0;
}
