#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, P{}, V{};
	for (int tc = 1; cin >> L >> P >> V, L; ++tc) {
		int ans = V / P * L + min(V % P, L);
		cout << "Case " << tc << ": " << ans << "\n";
	}
	return 0;
}
