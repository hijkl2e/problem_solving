#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A, B;
	while (N--) {
		int x{};
		cin >> x;
		if (x % 2) {
			A.push_back(x);
		} else {
			B.push_back(x);
		}
	}
	int ans = accumulate(A.begin(), A.end(), 0) + accumulate(B.begin(), B.end(), 0);
	if (ans % 2) {
		ans -= *min_element(A.begin(), A.end());
	}
	cout << ans << "\n";
	return 0;
}
