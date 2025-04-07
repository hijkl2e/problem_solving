#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		A[i] = A[i] == 1 ? 1 : -1;
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int ans = *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end());
	cout << ans << "\n";
	return 0;
}
