#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 1;
	for (int i = 1, j = 6; i < N; i += j, j += 6) {
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
