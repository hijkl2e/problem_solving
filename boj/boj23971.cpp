#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, N{}, M{};
	cin >> R >> C >> N >> M;
	int ans = ((R - 1) / (N + 1) + 1) * ((C - 1) / (M + 1) + 1);
	cout << ans << "\n";
	return 0;
}
