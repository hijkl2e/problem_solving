#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 6;
	while (N > 10) {
		ans *= N--;
	}
	cout << ans << "\n";
	return 0;
}
