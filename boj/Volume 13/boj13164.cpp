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
		B[i] = A[i + 1] - A[i];
	}
	sort(B.begin(), B.end());
	int ans = accumulate(B.begin(), B.end() - K + 1, 0);
	cout << ans << "\n";
	return 0;
}
