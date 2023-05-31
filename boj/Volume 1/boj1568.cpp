#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 44721; i > 0; --i) {
		int x = i * (i + 1) / 2;
		while (N >= x) {
			N -= x;
			ans += i;
		}
	}
	cout << ans << "\n";
	return 0;
}
