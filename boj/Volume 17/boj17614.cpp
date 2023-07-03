#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j) {
			int r = j % 10;
			if (r && r % 3 == 0) {
				++ans;
			}
			j /= 10;
		}
	}
	cout << ans << "\n";
	return 0;
}
