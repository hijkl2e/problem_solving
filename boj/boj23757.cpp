#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		pq.push(x);
	}
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	bool flag = true;
	for (int i = 0; i < M; ++i) {
		int x = pq.top(); pq.pop();
		if (x < A[i]) {
			flag = false;
			break;
		}
		pq.push(x - A[i]);
	}
	cout << flag << "\n";
	return 0;
}
