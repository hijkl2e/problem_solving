#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> A(2 << K);
	for (int i = 2; i < A.size(); ++i) {
		cin >> A[i];
	}
	int ans = accumulate(A.begin(), A.end(), 0);
	for (int i = A.size() - 2; i > 1; i -= 2) {
		if (A[i] < A[i + 1]) {
			swap(A[i], A[i + 1]);
		}
		A[i / 2] += A[i];
		ans += A[i] - A[i + 1]; 
	}
	cout << ans << "\n";
	return 0;
}
