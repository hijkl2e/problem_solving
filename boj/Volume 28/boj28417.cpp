#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2);
	vector<int> B(5);
	int ans{};
	while (N--) {
		cin >> A[0] >> A[1];
		for (int i = 0; i < 5; ++i) {
			cin >> B[i];
		}
		sort(B.rbegin(), B.rend());
		int res = max(A[0], A[1]) + B[0] + B[1];
		ans = max(ans, res);
	}
	cout << ans << "\n";
	return 0;
}
