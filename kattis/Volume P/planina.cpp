#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = (1 << N) + 1;
	ans *= ans;
	cout << ans << "\n";
	return 0;
}
