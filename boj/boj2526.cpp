#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	vector<int> A(1001, -1);
	int x = N, ans{};
	for (int i = 0;; ++i) {
		if (A[x] == -1) {
			A[x] = i;
			x = x * N % P;
		} else {
			ans = i - A[x];
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
