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
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				if (--K == 0) {
					i = -1;
					break;
				}
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
