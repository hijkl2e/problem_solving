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
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	deque<bool> B(M + 1);
	for (int i = 0; i < A.size(); ++i) {
		for (int j = A[i]; j <= M; j += A[i]) {
			B[j] = true;
		}
	}
	int ans = accumulate(B.begin(), B.end(), 0);
	cout << ans << "\n";
	return 0;
}
