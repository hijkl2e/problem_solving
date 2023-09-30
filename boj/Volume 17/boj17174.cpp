#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans{};
	while (N) {
		ans += N;
		N /= M;
	}
	cout << ans << "\n";
	return 0;
}
