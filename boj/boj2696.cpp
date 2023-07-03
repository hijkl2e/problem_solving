#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int M{};
		cin >> M;
		vector<int> A(++M);
		A[0] = 1 << 31;
		for (int i = 1; i < M; ++i) {
			cin >> A[i];
		}
		priority_queue<int> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;
		cout << M / 2 << "\n";
		for (int i = 0; i < M / 2; ++i) {
			pq1.push(A[2 * i]);
			pq2.push(A[2 * i + 1]);
			while (pq1.top() > pq2.top()) {
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(pq2.top());
				pq2.pop();
			}
			cout << (i == 0 || i % 10 ? "" : "\n") << pq2.top() << (i % 10 == 9 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}
