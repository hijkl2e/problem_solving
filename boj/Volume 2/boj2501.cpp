#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans{};
	for (int i = 1, j = 0; i <= N; ++i) {
		if (N % i == 0 && ++j == K) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
