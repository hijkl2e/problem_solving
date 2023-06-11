#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = ((N + 1) / 2) * ((N + 1) / 2 + 1) + (N % 2 == 0 ? N / 2 + 1 : 0);
	cout << ans << "\n";
	return 0;
}
