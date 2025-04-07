#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N * (N - 1) / 2);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	if (N == 2) {
		cout << min(A[0], 0) << " " << max(A[0], 0) << "\n";
		return 0;
	}
	sort(A.begin(), A.end());
	vector<int> B(N);
	bool yes{};
	for (int i = 2; i < N; ++i) {
		if ((A[0] + A[1] + A[i]) % 2) {
			continue;
		}
		int x = (A[0] + A[1] + A[i]) / 2;
		B[0] = x - A[i];
		B[1] = x - A[1];
		B[2] = x - A[0];
		priority_queue<int, vector<int>, greater<int>> pq1, pq2;
		for (int j = 2; j < A.size(); ++j) {
			if (i == j) {
				continue;
			}
			pq1.push(A[j]);
		}
		for (int j = 3; j < N; ++j) {
			B[j] = pq1.top() - B[0];
			for (int k = 0; k < j; ++k) {
				pq2.push(B[k] + B[j]);
			}
			while (pq1.size() && pq2.size() && pq1.top() == pq2.top()) {
				pq1.pop();
				pq2.pop();
			}
		}
		if (pq1.empty()) {
			yes = true;
			break;
		}
	}
	if (yes) {
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	} else {
		cout << "Impossible\n";
	}
	return 0;
}
