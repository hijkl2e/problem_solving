#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int pa{}, ka{}, pb{}, kb{}, n{};
	cin >> pa >> ka >> pb >> kb >> n;
	int ans_x{}, ans_y{}, ans_z = 1e9;
	for (int i = 0; i < 101; ++i) {
		int x = max(n - ka * i, 0);
		int y = x ? (x - 1) / kb + 1 : 0;
		int z = pa * i + pb * y;
		if (ans_z > z) {
			ans_x = i;
			ans_y = y;
			ans_z = z;
		}
	}
	cout << ans_x << " " << ans_y << " " << ans_z << "\n";
	return 0;
}
