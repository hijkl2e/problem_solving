#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	int ans = 1;
	for (int i = 1; i < K; ++i) {
		if (A[i - 1] > A[i]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
