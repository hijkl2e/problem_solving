#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(11, -1);
	int ans{};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		if (A[x] == (y ^ 1)) {
			++ans;
		}
		A[x] = y;
	}
	cout << ans << "\n";
	return 0;
}
