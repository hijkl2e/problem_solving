#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> A;
	while (K--) {
		int x{};
		cin >> x;
		if (x) {
			A.push_back(x);
		} else {
			A.pop_back();
		}
	}
	int ans = accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
