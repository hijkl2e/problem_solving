#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N / 5 + (N % 5 ? N % 5 % 2 ? 1 : 2 : 0);
	if (N == 1 || N == 2 || N == 4 || N == 7) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
