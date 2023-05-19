#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	vector<int> B(M + K);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M + K; ++i) {
		cin >> B[i];
	}
	for (int i = M; i < M + K; ++i) {
		B[i] = B[i] / sqrt(2);
	}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	int ans{};
	for (int i = 0; i < M + K && ans < N; ++i) {
		if (B[i] < A[ans]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
