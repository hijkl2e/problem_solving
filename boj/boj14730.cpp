#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		ans += a * b;
	}
	cout << ans << "\n";
	return 0;
}
