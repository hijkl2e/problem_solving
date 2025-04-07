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
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B(N);
		int ans{};
		while (true) {
			for (int i = 0; i < N; ++i) {
				A[i] += A[i] % 2;
			}
			if (count(A.begin(), A.end(), A[0]) == N) {
				break;
			}
			B[0] = (A[0] + A[N - 1]) / 2;
			for (int i = 1; i < N; ++i) {
				B[i] = (A[i] + A[i - 1]) / 2;
			}
			swap(A, B);
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
