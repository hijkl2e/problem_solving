#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	queue<int> q;
	int x{};
	while (cin >> x, x != -1) {
		if (x) {
			if (q.size() < N) {
				q.push(x);
			}
		} else {
			q.pop();
		}
	}
	if (q.size()) {
		while (q.size()) {
			x = q.front(); q.pop();
			cout << x << (q.size() ? " " : "\n");
		}
	} else {
		cout << "empty\n";
	}
	return 0;
}
