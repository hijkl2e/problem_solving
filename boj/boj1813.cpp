#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(51);
	while (N--) {
		int x{};
		cin >> x;
		++A[x];
	}
	int ans = -1;
	for (int i = 0; i < 51; ++i) {
		if (A[i] == i) {
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}
