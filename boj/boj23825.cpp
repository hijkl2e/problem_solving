#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans = min(N, M) / 2;
	cout << ans << "\n";
	return 0;
}
