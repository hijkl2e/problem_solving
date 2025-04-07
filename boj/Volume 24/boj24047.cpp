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
	vector<int> B(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		B[i] = i;
	}
	vector<int> C;
	while (B.size()) {
		for (int x : B) {
			if (A[x] > A[x + 1]) {
				swap(A[x], A[x + 1]);
				if (--K == 0) {
					C.clear();
					break;
				}
				if (x) {
					C.push_back(x - 1);
				}
			}
		}
		swap(B, C);
		C.clear();
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
