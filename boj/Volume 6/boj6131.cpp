#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i < 501; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i * i == j * j + N) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
