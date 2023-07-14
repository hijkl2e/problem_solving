#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, B{};
	cin >> R >> B;
	int ans_x{}, ans_y{};
	for (int i = 1;; ++i) {
		if ((R + B) % i) {
			continue;
		}
		int j = (R + B) / i;
		if (i + j - 2 == R / 2) {
			ans_x = j, ans_y = i;
			break;
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
