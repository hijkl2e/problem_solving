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
	if (A[N - 1] != N + 1) {
		cout << "Error\n";
		return 0;
	}
	vector<int> D(N + 2);
	for (int i = 0; i < N; ++i) {
		++D[A[i]];
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N + 1; ++i) {
		if (D[i] == 0) {
			pq.push(i);
		}
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = pq.top(); pq.pop();
		if (--D[A[i]] == 0) {
			pq.push(A[i]);
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
