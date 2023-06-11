#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> K(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> K[i];
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		q.push(i);
	}
	while (q.size() > 1) {
		int k = (K[q.front()] - 1) % q.size();
		while (k--) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	cout << q.front() << "\n";
	return 0;
}
