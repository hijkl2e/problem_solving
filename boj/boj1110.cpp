#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{}, x = N;
	do {
		x = x % 10 * 10 + (x / 10 + x % 10) % 10;
		++ans;
	} while (x != N);
	cout << ans << "\n";
	return 0;
}
