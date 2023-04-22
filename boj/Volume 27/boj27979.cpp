#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	int ans = N;
	for (int i = N - 1; i >= 0; --i) {
		if (A[i] == B[ans - 1]) {
			--ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
