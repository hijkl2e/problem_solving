#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{}, X{}, Y{};
	cin >> N >> P >> X >> Y;
	int ans = P * X + P / (N - 1) * Y;
	cout << ans << "\n";
	return 0;
}
