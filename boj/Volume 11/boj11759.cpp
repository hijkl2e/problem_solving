#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s{}, v1{}, v2{};
	cin >> s >> v1 >> v2;
	ii ans{-1, -1};
	for (int i = 0; i * v2 <= s; ++i) {
		if ((s - i * v2) % v1 == 0) {
			ans = {(s - i * v2) / v1, i};
			break;
		}
	}
	if (ans.first == -1) {
		cout << "Impossible\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
