#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N = N / 2 - 2;
	int ans = N > 0 ? N * (N + 1) / 2 : 0;
	cout << ans << "\n";
	return 0;
}
