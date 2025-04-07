#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		if (N % 2) {
			fill(A.begin(), A.end(), 1);
		} else {
			fill(A.begin(), A.end(), 2);
			A[N - 2] = 1;
			A[N - 1] = 3;
		}
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
