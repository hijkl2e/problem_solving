#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, E{};
	cin >> N >> E;
	string p2 = to_string(1 << E);
	int ans{};
	for (int i = 0; i <= N; ++i) {
		if (to_string(i).find(p2) != -1) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
