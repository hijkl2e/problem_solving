#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> A(101);
	int ans{};
	while (N--) {
		int x{};
		cin >> x;
		if (A[x]) {
			++ans;
		}
		A[x] = true;
	}
	cout << ans << "\n";
	return 0;
}
