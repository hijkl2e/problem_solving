#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
	}
	int x{};
	cin >> x;
	int ans{};
	for (int i = 0; i < 4; ++i) {
		if (A[i] == x) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
