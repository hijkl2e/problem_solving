#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(10001);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		++A[x], --A[y];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int ans = A.size() - count(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
