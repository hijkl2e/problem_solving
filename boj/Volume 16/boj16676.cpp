#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 1;
	for (int i = 11; i <= N; i = 10 * i + 1) {
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
