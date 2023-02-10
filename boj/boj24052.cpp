#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i < N; ++i) {
		int j = i;
		int val = A[i];
		while (j && val < A[j - 1]) {
			A[j] = A[j - 1];
			if (--K == 0) {
				i = j = N;
				break;
			}
			--j;
		}
		if (i != j) {
			A[j] = val;
			if (--K == 0) {
				break;
			}
		}
	}
	if (K) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
