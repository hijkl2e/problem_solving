#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		int ans{};
		for (int i = 1; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if ((i * i + j * j + M) % (i * j) == 0) {
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
