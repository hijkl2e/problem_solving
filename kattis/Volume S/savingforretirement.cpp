#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int B{}, Br{}, Bs{}, A{}, As{};
	cin >> B >> Br >> Bs >> A >> As;
	int ans{};
	for (int i = 0;; ++i) {
		if (i * As > (Br - B) * Bs) {
			ans = A + i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
