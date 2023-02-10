#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i < N; ++i) {
		int j = i;
		int sum = i;
		while (j) {
			sum += j % 10;
			j /= 10;
		}
		if (sum == N) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
