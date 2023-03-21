#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; N >= i * (i + 1) / 2; ++i) {
		if ((N - i * (i + 1) / 2) % i == 0) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
