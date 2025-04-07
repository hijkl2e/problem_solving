#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N = (N - 1) % 8 + 1;
	int ans = N > 5 ? 10 - N : N;
	cout << ans << "\n";
	return 0;
}
