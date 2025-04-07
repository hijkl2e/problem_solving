#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<int> pq;
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		int x = A[i] - i;
		pq.push(x);
		if (pq.top() > x) {
			pq.pop();
			pq.push(x);
		}
		B[i] = pq.top() + i;
	}
	for (int i = N - 2; i >= 0; --i) {
		B[i] = min(B[i], B[i + 1] - 1);
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
