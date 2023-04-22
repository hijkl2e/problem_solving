#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	deque<bool> A(100001);
	while (N--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	int ans{};
	for (int i = 1; i < A.size() && i < M - i; ++i) {
		if (M - i < A.size() && A[i] && A[M - i]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
