#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, D{};
		cin >> N >> D;
		int ans{};
		while (N--) {
			int v{}, f{}, c{};
			cin >> v >> f >> c;
			if (D * c <= f * v) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
