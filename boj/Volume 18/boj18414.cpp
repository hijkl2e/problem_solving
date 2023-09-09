#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, L{}, R{};
	cin >> X >> L >> R;
	int ans = X < L ? L : R < X ? R : X;
	cout << ans << "\n";
	return 0;
}
