#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		for (int i = 0; i < N; ++i) {
			cout << A[(N - i) % N] << "-" << (i % 2 ? "B" : "A") << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
