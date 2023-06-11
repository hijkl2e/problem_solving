#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A, B;
	while (N--) {
		int x{};
		cin >> x;
		if (x > 0) {
			A.push_back(x);
		} else {
			B.push_back(-x);
		}
	}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	int ans{};
	for (int i = 0; i < A.size(); i += M) {
		ans += A[i];
	}
	for (int i = 0; i < B.size(); i += M) {
		ans += B[i];
	}
	ans = 2 * ans - max(A.size() ? A[0] : -1, B.size() ? B[0] : -1);
	cout << ans << "\n";
	return 0;
}
