#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string L, R;
	cin >> L >> R;
	int ans{};
	if (L.size() == R.size()) {
		for (int i = 0; i < L.size(); ++i) {
			if (L[i] == R[i]) {
				if (L[i] == '8') {
					++ans;
				}
			} else {
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
