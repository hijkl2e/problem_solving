#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> chk(1e3 + 1);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		chk[x] = true;
	}
	for (int i = 0; i < N - 1; ++i) {
		int x{};
		cin >> x;
		chk[x] = false;
	}
	int ans = find(chk.begin(), chk.end(), true) - chk.begin();
	cout << ans << "\n";
	return 0;
}
