#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{};
	cin >> A >> B;
	int ans = 1;
	while (A < B) {
		if (B % 2) {
			if (B % 10 != 1) {
				break;
			}
			B /= 10;
		} else {
			B /= 2;
		}
		++ans;
	}
	if (A != B) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
