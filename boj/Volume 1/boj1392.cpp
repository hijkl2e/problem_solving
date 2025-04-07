#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	while (Q--) {
		int x{};
		cin >> x;
		int ans = upper_bound(A.begin(), A.end(), x) - A.begin();
		cout << ans << "\n";
	}
	return 0;
}
