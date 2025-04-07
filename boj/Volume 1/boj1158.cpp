#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		q.push(i);
	}
	cout << "<";
	while (q.size()) {
		for (int i = 0; i < K - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		int x = q.front(); q.pop();
		cout << x << (q.size() ? ", " : ">\n");
	}
	return 0;
}
