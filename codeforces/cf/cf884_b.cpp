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
		if (N < 3) {
			cout << (N == 1 ? "1" : "1 2") << "\n";
			continue;
		}
		vector<int> A(N - 1);
		for (int i = 1; i < A.size() - 1; ++i) {
			A[i] = i + 3;
		}
		A[0] = 2, A[N - 2] = 3;
		A.insert(A.begin() + N / 2, 1);
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
