#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0, j = 0; i < N; ++i) {
		if (j + 1 < A[i] && B[j] == 0) {
			++j;
		}
		if (B[j]) {
			--B[j];
		}
	}
	bool yes = accumulate(B.begin(), B.end(), 0) == 0;
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
