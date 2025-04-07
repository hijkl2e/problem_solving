#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	--M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<int> pq1, pq2;
	multiset<int> S;
	for (int i = 0; i < 2 * M; ++i) {
		pq1.push(A[i]);
	}
	vector<int> B;
	for (int i = 2 * M; i < N; ++i) {
		pq1.push(A[i]);
		B.push_back(pq1.top());
		pq2.push(A[i - 2 * M]);
		while (pq1.size() && pq2.size() && pq1.top() == pq2.top()) {
			pq1.pop();
			pq2.pop();
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
