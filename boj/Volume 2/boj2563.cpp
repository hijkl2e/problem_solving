#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<deque<bool>> A(101, deque<bool>(101));
	int N{};
	cin >> N;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				A[x + i][y + j] = true;
			}
		}
	}
	int ans{};
	for (int i = 0; i < A.size(); ++i) {
		ans += accumulate(A[i].begin(), A[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
