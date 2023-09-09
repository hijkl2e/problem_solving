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
	sort(A.begin(), A.end());
	partial_sum(A.begin(), A.end(), A.begin());
	while (Q--) {
		int l{}, r{};
		cin >> l >> r;
		cout << A[r] - A[l - 1] << "\n";
	}
	return 0;
}
