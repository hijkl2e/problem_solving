#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans = 1;
	while (N) {
		N -= (N - 1) / K + 1;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
