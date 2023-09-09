#include <bits/stdc++.h>

using namespace std;

vector<int> A;

void solve(int x, int n) {
	A.push_back(x);
	if (n == 9) {
		return;
	}
	solve(10 * x + 4, n + 1);
	solve(10 * x + 7, n + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve(0, 0);
	sort(A.begin(), A.end());
	int a{}, b{};
	cin >> a >> b;
	int ans = upper_bound(A.begin(), A.end(), b) - lower_bound(A.begin(), A.end(), a);
	cout << ans << "\n";
	return 0;
}
