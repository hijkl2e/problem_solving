#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (x) {
			A.push_back(i);
		}
	}
	int x{}, y = A.back() + 1, z{};
	if (y > N - A.front()) {
		x = 1;
		y = N - A.front();
	}
	for (int i = 1; i < A.size(); ++i) {
		int cnt = 2 * (A[i - 1] + 1) + (N - A[i]);
		if (y > cnt) {
			x = 2;
			y = cnt;
			z = i - 1;
		}
		cnt = 2 * (N - A[i]) + (A[i - 1] + 1);
		if (y > cnt) {
			x = 3;
			y = cnt;
			z = i;
		}
	}
	string ans;
	if (x < 2) {
		ans = string(y, x ? 'R' : 'L');
	} else if (x == 2) {
		ans = string(A[z] + 1, 'L') + string(N + A[z] - A[z + 1] + 1, 'R');
	} else {
		ans = string(N - A[z], 'R') + string(N - A[z] + A[z - 1] + 1, 'L');
	}
	cout << ans.size() << "\n" << ans << "\n";
	return 0;
}
